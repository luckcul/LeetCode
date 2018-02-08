class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int length = nums.size();
        if(length < 3) return false; 
        vector<int> max_(length, nums[length-1]); 
        vector<int> min_(length, nums[0]);
        for(int i = 1; i < length; i++) {
            min_[i] = min(min_[i-1], nums[i-1]); 
        }
        for(int i = length -2; i >= 0; i--) {
            max_[i] = max(max_[i+1], nums[i+1]);
        }
        for(int i = 1; i < length - 1; i++) {
            if(nums[i] > min_[i] && nums[i] < max_[i]) return true;
        }
        return false;
    }
};


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m1 = (1<<31)-1, m2 = m1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] <= m1) {
                m1 = nums[i];
            }
            else if(nums[i] <= m2) {
                m2 = nums[i];
            }
            else return true;
        }
        return false;
    }
};