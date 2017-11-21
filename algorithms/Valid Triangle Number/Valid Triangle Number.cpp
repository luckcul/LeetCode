class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ret = 0; 
        int length = nums.size(); 
        sort(nums.begin(), nums.end());
        for(int i = 0; i < length; i++) {
            for(int j = i+1; j < length-1; j++) {
                int k = j + 1;
                while(k < length && nums[k] < nums[i] + nums[j]) {
                    k++;
                }
                ret += k - j - 1;
            }
        }
        return ret;
    }
};

// true O(n^2)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ret = 0; 
        int length = nums.size(); 
        sort(nums.begin(), nums.end());
        for(int k = length - 1; k >= 2; k --) {
            int i = 0, j = k-1; 
            while(i < j) {
                if(nums[i] + nums[j] > nums[k]) {
                    ret += j - i;
                    j --;
                }
                else i++;
            }
        }
        return ret;
    }
};