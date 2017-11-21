class Solution {
public:
    string countAndSay(int n) {
        string ret = "1";
        for(int i = 2; i <= n; i++) {
            string new_ret = "";
            char last = ret[0];
            int count = 1;
            for(int j = 1; j < ret.size(); j++){
                if(last == ret[j]) {
                    count++;
                }
                else {
                    string times = "0";
                    times[0] += count;
                    string dig = "0"; dig[0] = last;
                    new_ret = new_ret + times +  dig;
                    last = ret[j]; count = 1;
                }
            }
            string times = "0";
            times[0] += count;
            string dig = "0"; dig[0] = last;
            new_ret = new_ret + times +  dig;
            ret = new_ret;
        }
        return ret;
    }
};