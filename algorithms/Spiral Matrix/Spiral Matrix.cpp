class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
        int n = matrix.size(); 
        if(n == 0) return ret;
        int m = matrix[0].size();
        int l = 0, r = m-1, t = 0, b = n-1;
        int nowDir = 0, lx = 0, ly = -1;
        while(l <= r && t <= b) {
            int dx = dir[nowDir][0], dy = dir[nowDir][1];
            while(lx + dx >= t && lx + dx <= b && ly + dy >= l && ly + dy <= r) {
                lx += dx; ly += dy;
                ret.push_back(matrix[lx][ly]);
            }
            if(nowDir == 0) t++;
            else if(nowDir == 1) r--;
            else if(nowDir == 2) b--;
            else  l++;
            nowDir += 1;
            nowDir %= 4;
        }
        return ret;
    }
};