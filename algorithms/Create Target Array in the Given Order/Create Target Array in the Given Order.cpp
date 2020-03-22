class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int len = nums.size(); 
        vector<int> ret(len, -1); 
        for(int i = 0; i < len; i++) {
            int val = nums[i]; 
            int idx = index[i]; 
            // cout<<ret[idx]<<endl;
            if(ret[idx] == -1) {
                ret[idx] = val; 
            } 
            else {
                for(int j = len-1; j > idx; j--) {
                    ret[j] = ret[j-1]; 
                }
                ret[idx] = val; 
            }
        }
        return ret; 
    }
};