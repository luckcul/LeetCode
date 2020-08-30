class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int len = nums.size(); 
        vector<int> zeros; 
        zeros.push_back(-1); 
        for(int i= 0; i<len; i++) {
            if(nums[i] == 0) zeros.push_back(i); 
        }
        zeros.push_back(len); 
        int ret = 0; 
        for(int i = 1; i < zeros.size(); i++) {
            int start = zeros[i-1]+1; 
            int end = zeros[i]-1;
            int status = 0;  
            for(int j = start; j <= end; j++) {
                if(nums[j] < 0) {
                    status = 1-status; 
                }
                if(status==0) {
                    ret = max(ret, j-start+1); 
                }
            }
            status=0; 
            for(int j = end; j >= start; j--) {
                if(nums[j] < 0) status = 1-status; 
                if( status==0) {
                    ret = max(ret, end-j+1); 
                }
            }
        }
        return ret; 
    }
};