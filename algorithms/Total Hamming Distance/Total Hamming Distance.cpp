class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> bitcount(33, 0);
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < 31; j++) {
                if(nums[i] & (1<<j)) bitcount[j] ++;
            }
        }
        int ret = 0;
        for(int i = 0; i < 31; i++) ret += bitcount[i] * (nums.size() - bitcount[i]);
        return ret;
    }
};