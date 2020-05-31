class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        int ret = 0; 
        int len = nums.size(); 
        ret = max(ret, (nums[0]-1) * (nums[1]-1)); 
        ret = max(ret, (nums[len-1]-1) * (nums[len-2] -1)); 
        return ret; 
    }
};