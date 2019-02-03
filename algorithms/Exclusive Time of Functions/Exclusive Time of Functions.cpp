class Solution {
    struct node {
        bool start;
        int fun_id; 
        int timestamp; 
        node(bool s, int idx, int times):start(s),fun_id(idx),timestamp(times){}
    };
    int string_to_int(string s) {
        int ret = 0; 
        for(int i = 0; i < s.size(); i++) {
            ret *= 10; 
            ret += s[i] - '0';
        }
        return ret; 
    }
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ret = vector<int>(n, 0); 
        stack<node> s1; 
        stack<int>s2; 
        
        int len = logs.size(); 
        for(int i = 0; i < len; i++) {
            string si = logs[i]; 
            int idx1 = si.find(':');
            int idx2 = si.find_last_of(':');
            int fun_id = string_to_int(si.substr(0, idx1)); 
            int timestamp = string_to_int(si.substr(idx2+1)); 
            bool start = logs[i][idx1+1] == 's';
            node now = node(start, fun_id, timestamp); 
            if(start) {
                s1.push(now);
                s2.push(0); 
            }
            else {
                now.timestamp ++;
                node last = s1.top(); 
                s1.pop(); 
                int tot_time = now.timestamp - last.timestamp;
                int sub_time = s2.top(); 
                s2.pop(); 
                ret[last.fun_id] += tot_time - sub_time; 
                if(!s2.empty()) {
                    s2.top() += tot_time;
                }
            }
        }
        return ret; 
    }
};