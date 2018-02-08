class Solution {
public:
    vector<string> split(string s) {
        vector<string> ret; 
        int index = -1; 
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                if(i-index <= 1) {
                    index = i;continue;
                }
                ret.push_back(s.substr(index+1, i-index-1));
                index = i;
            }
        }
        if(s.back() != ' '){
            ret.push_back(s.substr(index+1));
        }
        return ret;
    }
    bool wordPattern(string pattern, string str) {
        auto vec_str = split(str);
        if(vec_str.size() != pattern.size()) return false;
        for(int i = 0; i < pattern.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(!((pattern[i] == pattern[j]) == (vec_str[i] == vec_str[j]))){
                    return false;
                }
            }
        }
        return true;
    }
};