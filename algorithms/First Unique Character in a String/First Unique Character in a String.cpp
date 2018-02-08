class Solution {
public:
    int firstUniqChar(string s) {
        int vis[30] = {0}; 
        for(int i = 0; i < s.size(); i++) {
            vis[s[i] - 'a'] += 1;
        }
        for(int i = 0; i < s.size(); i++) {
            if(vis[s[i] - 'a'] <= 1) return i;
        }
        return -1;
    }
};