class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int len = nums.size(); 
        vector<int> ret; 
        sort(nums.begin(), nums.end()); 
        int s = 0; 
        for(int i = 0; i < len; i++) {
            s += nums[i]; 
        }
        int s1 = 0; 
        for(int i = len-1; i >= 0; i--) {
            s1 += nums[i]; 
            s -= nums[i]; 
            ret.push_back(nums[i]); 
            if(s1 > s) {
                break; 
            }
        }
        return ret; 
    }
};