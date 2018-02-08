class Solution { 
    vector<int> nums;
public:
    Solution(vector<int> nums):nums(nums) { 
        srand(time(0));
    }
    
    int pick(int target) {
        int ret = 0, cnt = 0; 
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != target) continue;
            cnt ++;
            if(rand() % cnt == 0) ret = i;
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */