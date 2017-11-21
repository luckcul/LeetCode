class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret; 
        for(int i = 1; i <= n; i++) {
            string tmp = ""; 
            if(i % 3 == 0) tmp += "Fizz";
            if(i % 5 == 0) tmp += "Buzz"; 
            if((i % 3) && (i % 5)) tmp += toString(i);
            ret.push_back(tmp);
        }
        return ret;
    }
    string toString(int x) {
        string ret = "";
        while(x) {
            int dig = x % 10; 
            x /= 10; 
            string tmp = "";
            tmp += ('0' + dig);
            ret = tmp + ret;
        }
        return ret;
    }
};