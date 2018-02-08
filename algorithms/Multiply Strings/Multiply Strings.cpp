class Solution {
public:
    string multiply(string num1, string num2) {
        int length1 = num1.size(); 
        int length2 = num2.size();
        int length = length1+length2;
        vector<char> ans = vector<char>(length, '0');
        for(int i = 0; i < length1; i++) {
            int last = 0; 
            int xi = length1-i-1;
            for(int j = 0; j < length2; j++) {
                int xj = length2-j-1;
                int now_value = (num1[xi] - '0') * (num2[xj] - '0');
                now_value += last;
                now_value += ans[i+j] - '0';
                ans[i+j] = '0' + (now_value % 10); 
                last = now_value / 10;
            }
            if(last) {
                ans[i+length2] += last;
            }
        }
        string ret = "";
        bool flag = false;
        for(int i = length-1; i >= 0; i--) if(ans[i] != '0' || flag) ret += ans[i], flag = true;
        if(ret.size() == 0) ret = "0";
        return ret;
    }
};