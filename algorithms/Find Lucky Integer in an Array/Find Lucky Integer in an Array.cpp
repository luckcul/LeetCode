class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> cnt(511, 0); 
        int maxv = 0; 
        int length = arr.size(); 
        int ret = -1; 
        for(int i = 0; i < length; i++) {
            cnt[arr[i]] ++; 
        }
        for(int i = 1; i <= 500; i++) {
            if(cnt[i] == i) {
                ret = max(ret, i); 
            }
        }
        return ret; 
    }
};