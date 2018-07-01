class Solution {
    vector<vector<int>> ret; 
    void dfs(vector<int> &nums, int cnt) {
        int length = nums.size(); 
        if(cnt >= length-1) {
            vector<int> tmp(nums); 
            ret.push_back(tmp); 
            return ;
        }
        for(int i = cnt; i < length; i++) {
            swap(nums[i], nums[cnt]);
            dfs(nums, cnt+1); 
            swap(nums[i], nums[cnt]); 
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0); 
        return this->ret; 
    }
};