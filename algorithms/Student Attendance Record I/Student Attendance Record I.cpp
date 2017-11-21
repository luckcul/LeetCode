class Solution {
public:
    bool checkRecord(string s) {
        int sumA = 0, sumL = 0; 
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'A') sumA++, sumL = 0;
            else if(s[i] == 'L') sumL ++;
            else sumL = 0;
            if(sumA > 1 || sumL > 2) return false;
        }        
        return true;
    }
};