class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ret = 0;
        sort(nums.begin(), nums.end());
        int last = 1e8, p1 = 0, p2 = 0;
        while(p1 < nums.size()) {
            if(nums[p1] == last) {
                p1++;
                continue;
            }
            if(p2 <= p1) p2 = p1 + 1;
            while(p2 < nums.size() && nums[p2] - nums[p1] < k) p2 ++;
            if(p2 >= nums.size()) break;
            if(nums[p1] - nums[p2] == -k) ret ++;
            last = nums[p1];
            p1 ++;
        }
        return ret;
    }
};