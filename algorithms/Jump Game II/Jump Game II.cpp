class Solution {
public:
    int jump(vector<int>& nums) {
        int ret = 0, stepMax = 0, maxNow = 0; 
        for(int i = 0; i < nums.size()-1; i++) {
            maxNow = max(maxNow, i + nums[i]);
            if(stepMax == i) {
                ret ++;
                stepMax = maxNow;
            }
        }
        return ret;
    }
};