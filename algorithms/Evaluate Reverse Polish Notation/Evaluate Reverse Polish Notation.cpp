class Solution {
    int string_to_int(string s) {
        int ret = 0; 
        bool neg = (s[0] == '-');
        for(int i = neg ? 1:0; i < s.size(); i++) {
            ret *= 10; 
            ret += s[i] - '0';
        }
        return neg? -ret:ret;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> S;
        for(int i = 0; i < tokens.size(); i++) {
            string now = tokens[i];
            if((now[0] > '9' || now[0] < '0') && now.size() <= 1){
                int b = S.top();
                S.pop();
                int a = S.top();
                S.pop();
                if(now == "+"){
                    S.push(a+b);
                }
                else if(now == "-"){
                    S.push(a-b);
                }
                else if(now == "*"){
                    S.push(a*b);
                }
                else S.push(a/b);
            }
            else {
                S.push(string_to_int(now));
            }

        }
        return S.top();
    }
};