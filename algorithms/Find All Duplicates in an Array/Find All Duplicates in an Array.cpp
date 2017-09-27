class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        int index = 0;
        while(index < nums.size()) {
            int nowIndex = index;
            int nowNum = nums[nowIndex];
            index ++;
            if(nowNum == nowIndex + 1) continue;
            nums[nowIndex] = -1;
            while(true) {
               if(nowNum == -1) break;

               int nextIndex = nowNum - 1; 
               int nextNum = nums[nextIndex];
               if(nextNum == nowNum) {
                   ret.push_back(nextNum); break;
               }
               nums[nextIndex] = nowNum;
               nowNum = nextNum;
            }
        }
        return ret;
    }
};