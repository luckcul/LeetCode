class Solution {
    bool check(vector<vector<int>> &dungeon, int x) {
        int n = dungeon.size(); 
        int m = dungeon[0].size();
        vector<vector<int>> v = vector<vector<int>>(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0) v[i][j] = x + dungeon[i][j];
                else if(i == 0) v[i][j] = (v[i][j-1] > 0? v[i][j-1] + dungeon[i][j] : 0);
                else if(j == 0) v[i][j] = (v[i-1][j] > 0? v[i-1][j] + dungeon[i][j] : 0);
                else v[i][j] = max((v[i][j-1] > 0? v[i][j-1] + dungeon[i][j] : 0), (v[i-1][j] > 0? v[i-1][j] + dungeon[i][j] : 0));
            }
        }
        return v[n-1][m-1] > 0;
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int l = 0, r = (1<<31)-1, ans = 0;
        while(l <= r) {
            int m = (l+r)>>1;
            bool flag = check(dungeon, m);
            if(flag) {
                r = m-1;
                ans = m;
            }
            else {
                l = m+1;
            }
        }
        return max(1,ans); 
    }
};