class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long low_sum = 1; 
        int ret = 0, index=0;
        while(low_sum <= n) {
            if(index < nums.size() && nums[index] <= low_sum) {
                low_sum += nums[index];
                index ++;
            }
            else {
                low_sum += low_sum; 
                ret ++;
            }
        }
        return ret;
    }
};