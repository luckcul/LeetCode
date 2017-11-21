class Solution {
public:
    string convertToBase7(int num) {
        bool neg = false;
        if(num < 0) neg = true, num = -num;
        string ret = "";
        while(num) {
            string tmp = "";
            tmp += (char)('0' + (num % 7) );
            cout<<tmp<<endl;
            ret = tmp + ret;
            num /= 7;
        }
        if(ret.size() == 0) ret = "0";
        if(neg) ret = "-" + ret;
        return ret;
    }
};