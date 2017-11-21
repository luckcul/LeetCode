class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(k == 0) {
            int cou = 0; 
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] == 0) cou ++;
                else cou = 0; 
                if(cou >= 2) return true;
            }
            return false;
        }
        unordered_map<int, int> M;
        M[0] = -1;
        int s = 0;
        for(int i = 0; i < nums.size(); i++) {
            s += nums[i];
            s %= k;
            if(M.find(s) != M.end()) {
                int index = M[s];
                if(i - index >= 2) return true;
            }
            else M[s] = i;
        }
        return false;
    }
};