class Solution {
public:
    int findMin(vector<int>& nums) {
        int length = nums.size(); 
        int l = 0, r = length - 1, ret = min(nums[0], nums[r]);
        while(l < r) {
            int m = (l+r)>>1; 
            // cout<<l<<" "<<r<<" "<<m<<endl;
            if(nums[m] > nums[r]) {
                l = m+1;
            }
            else if(nums[m] < nums[r]) {
                ret = nums[m];r = m;
            }
            else r--;
        }
        return nums[l];
    }
};