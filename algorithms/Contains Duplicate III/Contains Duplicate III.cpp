class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long, int> M;
        int i = 0, j = 0; 
        for(; i < nums.size(); i++) {
            if(i - j > k) {
                if(M[nums[j]] == j) M.erase(nums[j]);
                j++;
            }
            long long lowerNum = (long long)nums[i] - t;
            map<long long, int>::iterator it = M.lower_bound(lowerNum);
            if(it != M.end() && abs(it->first - nums[i]) <= t) return true;
            M[nums[i]] = i;
        }
        return false;
    }
};