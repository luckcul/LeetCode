class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ret(nums.size(), -1); 
        stack<pair<int, int>> S;
        for(int i = 0; i < nums.size(); i++) {
            while(S.size()) {
                pair<int, int> topEle = S.top();
                if(topEle.second >= nums[i]) break;
                ret[topEle.first] = nums[i];
                S.pop();
            }
            S.push(make_pair(i, nums[i]));
        }
        for(int i = 0; i < nums.size(); i++) {
            while(S.size()) {
                pair<int, int> topEle = S.top();
                if(topEle.second >= nums[i]) break;
                ret[topEle.first] = nums[i];
                S.pop();
            }
        }
        return ret;
    }
};