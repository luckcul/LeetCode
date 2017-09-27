class Solution {
public:
    string frequencySort(string s) {
        vector<vector<int>> cnt(s.size()+1, vector<int>());
        vector<int> v(300, 0);
        for(int i = 0; i < s.size(); i++) {
            int val = s[i]; //(s[i] >= 'a' ? s[i] - 'a' : s[i] - 'A' + 30);
            v[val] ++;
        }
        for(int i = 0; i < 300; i++) {
            if(v[i]) {
                cnt[v[i]].push_back(i);
            }
        }
        string ret = "";
        for(int i = s.size(); i >= 1; i--) {
            for(int j = 0; j < cnt[i].size(); j++) {
                ret += string(i, '\0' + cnt[i][j]);
            }
        }
        return ret;
    }
};