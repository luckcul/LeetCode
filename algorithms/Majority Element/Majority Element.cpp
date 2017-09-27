class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret, times = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(times == 0) ret = nums[i], times ++;
            else if(ret == nums[i]) times++;
            else times--;
        }
        return ret;
    }
};