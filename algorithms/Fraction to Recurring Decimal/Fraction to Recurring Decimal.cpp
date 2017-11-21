class Solution {
    string intToString(long long x) {
        string ret = "";
        while(x) {
            string temp = "";
            temp += '0' + x % 10;
            ret = temp + ret;
            x /= 10;
        }
        if(ret.size() == 0) ret = "0";
        return ret;
    }
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        bool neg = false;
        long long numeratorLL = numerator, denominatorLL = denominator;
        if(numeratorLL < 0) neg = !neg, numeratorLL = -numeratorLL;
        if(denominatorLL < 0) neg = !neg, denominatorLL = -denominatorLL;
        long long head = numeratorLL / denominatorLL;
        long long left = numeratorLL % denominatorLL;
        string ret = intToString(head);
        if(left == 0) return neg ? "-" + ret : ret;
        ret += ".";
        vector<long long> decimals;
        unordered_map<long , int> M;
        int cycleStarter = -1;
        while(left) {
            if(M.find(left) != M.end()) {
                cycleStarter = M[left];
                break;
            }
            M[left] = decimals.size();
            left *= 10;
            long long header = left / denominatorLL;
            long long leftNew = left % denominatorLL;
            decimals.push_back(header);
            left = leftNew;
        }
        if(cycleStarter == -1) cycleStarter = decimals.size();
        for(int i = 0; i < cycleStarter; i++) ret += intToString(decimals[i]);
        if(cycleStarter != decimals.size()) {
            ret += "(";
            for(int i = cycleStarter; i < decimals.size(); i++)  ret += intToString(decimals[i]);
            ret += ")";
        }
        if(neg) ret = "-" + ret;
        return ret;

    }
};