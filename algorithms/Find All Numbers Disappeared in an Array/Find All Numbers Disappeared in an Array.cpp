class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= 0) continue;
            int now_val = nums[i];
            nums[i] = -1;
            while(now_val > 0 && nums[now_val-1] != now_val) {
                int next_val = nums[now_val-1];
                nums[now_val-1] = now_val;
                now_val = next_val;
            }
        }
        vector<int> ret; 
        for(int i = 0; i < nums.size(); i++) if(nums[i] <= 0) {
            ret.push_back(i+1);
        }
        return ret;
    }
};