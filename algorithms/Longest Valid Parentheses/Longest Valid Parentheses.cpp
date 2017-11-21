class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<int, int>> S;
        S.push(make_pair(-1, 0));
        int ret = 0; 
        for(int i = 0; i < s.size(); i++) {
            int now_index = i+1;
            int now_value = (s[i] == '(' ? 0 : 1);
            if(now_value == 0){
                S.push(make_pair(now_value, now_index));
            }
            else {
                pair<int, int> top = S.top();
                if(top.first == 0) {
                    S.pop();
                    ret = max(ret, now_index - S.top().second);
                }
                else {
                    S.push(make_pair(now_value, now_index));
                }
            }
        }
        return ret;
    }
};