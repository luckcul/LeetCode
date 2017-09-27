class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int i = 0; i < nums.size(); i++) {
            twos |= (ones & nums[i]);
            ones = ones^nums[i];
            int threes = twos & ones; 
            ones &= (~threes);
            twos &= (~threes);
        }
        return ones;
    }
};