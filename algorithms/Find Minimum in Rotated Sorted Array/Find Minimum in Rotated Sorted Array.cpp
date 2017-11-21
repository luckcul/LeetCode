class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1; 
        int ret = nums[0];
        while(l <= r) {
            int m = (l+r)>>1; 
            if(nums[m] <= nums[nums.size()-1]){
                r = m - 1; ret = nums[m];
            } 
            else l = m + 1;
        }
        return ret;
    }
};