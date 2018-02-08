class Solution {
    
public:
    bool find132pattern(vector<int>& nums) {
        int len = nums.size(); 
        stack<int> S; 
        int third = 1<<31; 
        for(int i = len-1; i >= 0; i--) {
            if(nums[i] < third) return true; 
            else {
                while(!S.empty() && nums[i] > S.top()) {
                    third = S.top();  S.pop(); 
                }
            }
            S.push(nums[i]); 
        }
        return false; 
    }
};