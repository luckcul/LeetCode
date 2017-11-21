class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret;
        int prod = 1;
        int num_zeros = 0; 
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) num_zeros ++;
            else prod *= nums[i];
        }
        for(int i = 0; i < nums.size(); i++) {
            int left_zeros = nums[i] ? num_zeros : num_zeros - 1;
            if(left_zeros) {
                ret.push_back(0); continue;
            }
            if(nums[i]) prod /= nums[i];
            ret.push_back(prod);
            if(nums[i]) prod *= nums[i];
        }
        return ret;
    }
};