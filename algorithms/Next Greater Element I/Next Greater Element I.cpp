class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> M;
        stack<int> S;
        for(int i = 0; i < nums.size(); i++) {
            while(S.size() > 0 && S.top() < nums[i]) {
                M[S.top()] = nums[i];
                S.pop();
            }
            S.push(nums[i]);
        }
        vector<int> ret;
        for(int i = 0;i < findNums.size(); i++) {
            ret.push_back(M.count(findNums[i]) ? M[findNums[i]] : -1);
        }
        return ret;
    }
};