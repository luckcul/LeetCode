class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end()); 
        string new_s = s + '$' + rev; 
        int len = new_s.length(); 
        vector<int> next(len+1, 0); 
        next[0] = -1; 
        int i = 0, j = -1; 
        while(i < len) {
            if(j == -1 || new_s[i] == new_s[j]) {
                i++; j++; 
                next[i] = j;
            }
            else j = next[j];
        }
        return rev.substr(0, rev.size()-next[len]) + s;
    }
};