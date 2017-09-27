class Solution {
    string toString(int num, bool flag) {
        string ret = "";
        while(num) {
            ret += ('0' + num % 10); 
            num /= 10;
        }
        reverse(ret.begin(), ret.end());
        if(ret.size() == 0) ret = "0";
        if(flag && ret.size() < 2) ret = "0" + ret;
        return ret;
    }
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ret;
        for(int i = 0; i < (1<<10); i++) {
            int s = 0; 
            for(int j = 0; j < 10; j++) if(i & (1<<j)) s ++;
            if(s != num) continue;
            int hours = 0, min = 0; 
            int index = 0; 
            for(; index < 4; index ++) if(i & (1<<index)) hours += (1<<index);
            for(; index < 10; index ++) if(i & (1<<index)) min += (1<<(index - 4));
            if(hours>= 12 || min >= 60) continue;
            ret.push_back(toString(hours, false) + ":" + toString(min, true));
        }
        return ret;
    }
};