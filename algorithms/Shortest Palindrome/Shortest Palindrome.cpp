class Solution {
public:
    string shortestPalindrome(string s) {
        int length = s.size(); 
        int i = length-1;
        for(; i >= 0; i--) {
            int st = 0, en = i; 
            while(st <= en) {
                if(s[st] == s[en]) st++, en--; 
                else break;
            }
            if(st > en) break;
        }
        string ret = ""; 
        for(int j = length-1; j > i; j--) ret += s[j]; 
        return ret + s; 
    }
};