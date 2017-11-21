class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> M;
        int sum = 0; 
        int ret = 0; 
        M[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int wanted = sum - k; 
            ret += M[wanted];
            if(M.find(sum) != M.end()) M[sum] ++; 
            else M[sum] = 1;
        }
        return ret;
    }
};