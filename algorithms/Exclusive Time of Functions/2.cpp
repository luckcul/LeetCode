class Solution {
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
        stack<pair<int, int>> s; 
        for(int i = 0; i < logs.size(); i++) {
            string si = logs[i]; 
            int idx1 = si.find_first_of(':'); 
            int idx2 = si.find_last_of(':'); 
            int fun_id = string_to_int(si.substr(0, idx1)); 
            int timestamp = string_to_int(si.substr(idx2+1)); 
            bool start = si[idx1+1] == 's';
            
            if(start) {
                if(!s.empty()) {
                    pair<int, int> last = s.top(); 
                    ret[last.first] += timestamp - last.second; 
                }
                s.push(make_pair(fun_id, timestamp)); 
            }
            else {
                pair<int, int> last = s.top(); 
                ret[last.first] += timestamp+1-last.second; 
                s.pop(); 
                if(!s.empty()) {
                    s.top().second = timestamp+1; 
                }
            }
        }
        return ret; 
    }
};