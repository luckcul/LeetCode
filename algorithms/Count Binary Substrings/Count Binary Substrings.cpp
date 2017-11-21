class Solution {
public:
    int countBinarySubstrings(string s) {
        int length = s.size(); 
        vector<int> left(length, 0); 
        vector<int> right(length, 0);
        for(int i = 0; i < length; i++) {
            if(i == 0) left[i] = 1;
            else {
                if(s[i] == s[i-1]) left[i] = left[i-1] + 1;
                else left[i] = 1;
            }
        }
        for(int i = length - 1; i >= 0; i --) {
            if(i == length - 1) right[i] = 1;
            else {
                if(s[i] == s[i+1] ) right[i] = right[i+1] + 1;
                else right[i] = 1;
            }
        }
        int ret = 0; 
        for(int i = 0; i < length-1; i++) {
            if(s[i] != s[i+1]) {
                ret += min(left[i], right[i+1]);
            }
        }
        return ret;
    }
};