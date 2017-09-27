class Solution {
    char getLower(char ch) {
        return ch >= 'a' ? ch : ch - 'A' + 'a';
    }
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ret; 
        map<char, int> M;
        string s[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < s[i].size(); j++) M[s[i][j]] = i;
        }
        for(int i = 0; i < words.size(); i++) {
            bool flag = true;
            for(int j = 1; j < words[i].size(); j++) {
                if(M[getLower(words[i][j])]!= M[getLower(words[i][j-1])]) {
                    flag = false;
                    break;
                }
            }
            if(flag) ret.push_back(words[i]);
        }
        return ret;
    }
};