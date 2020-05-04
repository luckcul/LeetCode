class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int len = nums.size(); 
        int last_idx = -1123456; 
        bool ret = true; 
        for(int i = 0; i < len; i++) {
            if(nums[i] == 0) continue; 
            if(i-last_idx-1 <k) {
                ret = false; 
                break; 
            }
            last_idx = i; 
        }
        return ret; 
    }
};