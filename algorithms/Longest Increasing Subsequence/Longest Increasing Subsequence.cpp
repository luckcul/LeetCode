
// O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ret = 0;
        vector<int> dp(nums.size(), 1);
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] >= nums[i] ) continue;
                dp[i] = max(dp[i], dp[j] + 1);
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};


// O(n* log(n))

class Solution {
    int binarySearch(vector<int> &record, int num) {
        int l = 0, r = record.size()-1;
        int ret = -1;
        while(l <= r) {
            int m = (l+r)>>1;
            if(record[m] < num) {
                ret = m;
                l = m + 1;
            }
            else r = m - 1;
        }
        return ret;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int ret = 0;
        vector<int> record(nums.size()+1, (1<<31)-1);
        record[0] = (1<<31);
        for(int i = 0; i < nums.size(); i++) {
            int index = binarySearch(record, nums[i]);
            ret = max(ret, index+1);
            record[index+1] = nums[i];
        }
        return ret;
    }
};