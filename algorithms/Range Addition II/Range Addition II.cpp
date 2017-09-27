class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int m_min = m, n_min = n;
        for(int i = 0; i < ops.size(); i++) {
            m_min = min(m_min, ops[i][0]);
            n_min = min(n_min, ops[i][1]);
        }
        return m_min * n_min;
    }
};