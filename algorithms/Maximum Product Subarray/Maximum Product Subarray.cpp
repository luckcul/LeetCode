class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ret = nums[0];
        int length = nums.size(), last = 1;
        bool have_zeros = false;
        for(int i = 0; i < length; i++) {
            if(nums[i] == 0) {
                have_zeros = true;
                last = 1;
                continue;
            }
            last *= nums[i];
            ret = max(ret, last);
        }
        last = 1;
        for(int i = length - 1; i >= 0; i--) {
            if(nums[i] == 0) {
                last = 1;continue;
            }
            last *= nums[i];
            ret = max(ret, last);
        }
        if(have_zeros) ret = max(ret, 0);
        return ret;
    }
};