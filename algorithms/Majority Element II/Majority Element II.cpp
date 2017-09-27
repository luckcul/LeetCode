class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int countN = 0, countM = 0, n = 0, m = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == n) countN ++;
            else if(nums[i] == m) countM ++;
            else if(countN == 0) countN = 1, n = nums[i];
            else if(countM == 0) countM = 1, m = nums[i];
            else countN --, countM --;
        }
        vector<int> ret;
        countN = 0, countM = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == n) countN ++;
            else if(nums[i] == m) countM ++;
        }
        if(countN > nums.size()/3) ret.push_back(n);
        if(countM > nums.size()/3) ret.push_back(m);
        return ret;
    }
};