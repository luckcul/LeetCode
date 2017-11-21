class Solution {
    static bool cmp(pair<int, int> x, pair<int, int> y) {
        if(x.second == y.second) {
            return x.first < y.first;
        }
        return x.second < y.second;
    }
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int, int>> p; 
        for(int i = 0; i < nums.size(); i++) {
            p.push_back(make_pair(i, nums[i]));
        }
        sort(p.begin(), p.end(), cmp); 
        for(int i = 1; i < p.size(); i++) {
            if(p[i].second == p[i-1].second) {
                if(p[i].first - p[i-1].first <= k) return true;
            }
        }
        return false;
    }
};