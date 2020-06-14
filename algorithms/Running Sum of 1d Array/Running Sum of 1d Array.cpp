class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ret; 
        int last = 0; 
        int len = nums.size(); 
        for(int i = 0; i < len; i++) {
            last += nums[i]; 
            ret.push_back(last); 
        }
        return ret; 
    }
};