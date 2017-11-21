class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '[') {
                S.push(ch);
            }
            else {
                if(S.empty()) return false;
                char now = S.top();
                if(ch == ')' && now != '(') return false;
                if(ch == '}' && now != '{') return false;
                if(ch == ']' && now != '[') return false;
                S.pop();
            }
        }
        if(S.empty()) return true;
        return false;
    }
};