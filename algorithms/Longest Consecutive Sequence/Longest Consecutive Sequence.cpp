class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> M;
        int ret = 0; 
        for(int i = 0; i < nums.size(); i++) {
            if(M.find(nums[i]) == M.end()){
                int left = M.find(nums[i] - 1) != M.end()? M[nums[i]-1]:0;
                int right = M.find(nums[i] + 1) != M.end()? M[nums[i] + 1]:0;
                int s = left + right + 1;
                M[nums[i]] = s;
                M[nums[i] - left] = s;
                M[nums[i] + right] = s;
                ret = max(ret, s);
            }
        }
        return ret;
    }
};