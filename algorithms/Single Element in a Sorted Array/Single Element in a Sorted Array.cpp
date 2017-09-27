class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ret = 0;
        for(int i = 0; i < nums.size(); i++) ret ^= nums[i];
        return ret;
    }
};