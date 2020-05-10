class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int len = target.size(); 
        vector<string> ret; 
        int idx = 1; 
        for(int i = 0; i < len; i++) {
            int num = target[i]; 
            while(idx < num) {
                ret.push_back("Push"); 
                ret.push_back("Pop"); 
                idx ++; 
            }
            ret.push_back("Push"); 
            idx++; 
        }
        return ret; 
    }
};