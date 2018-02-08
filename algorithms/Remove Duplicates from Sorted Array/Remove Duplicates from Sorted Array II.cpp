class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        bool r = false; 
        int i = 1, j = 1; 
        int len = nums.size(); 
        while(i < len) {
            if(nums[i] == nums[i-1]) {
                if(!r){
                    r = true; 
                    nums[j] = nums[i]; j++; 
                }
            }
            else {
                r = false; 
                nums[j] = nums[i]; j++; 
            }
            i++; 
        }
        return min(len, j); 
    }
};