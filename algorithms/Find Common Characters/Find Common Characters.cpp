class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> vis(30, 1123456); 
        int len = A.size(); 
        for(int i = 0; i < len; i++) {
            vector<int> vis_tmp(30, 0); 
            for(int j = 0; j < A[i].size(); j++) {
                int num = A[i][j] - 'a'; 
                vis_tmp[num]++; 
            }
            for(int j = 0; j <= 'z' - 'a'; j++) {
                vis[j] = min(vis[j], vis_tmp[j]);
            }
        }
        vector<string> ret; 
        for(int i = 0; i <= 'z'-'a'; i++) {
            for(int j = 0; j < vis[i]; j++) {
                string s = "a"; 
                s[0] += i;
                ret.push_back(s);
            }
        }
        return ret; 
    }
};