class Solution {
    unordered_map<int, vector<int>> M;
public:
    Solution(vector<int> nums) {
        srand(time(0));
        for(int i = 0; i < nums.size(); i++) {
            M[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int length = M[target].size();
        return M[target][rand() % length];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */