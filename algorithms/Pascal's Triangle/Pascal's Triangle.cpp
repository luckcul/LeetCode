class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        for(int i = 0; i < numRows; i++) {
            vector<int> tmp = vector<int>(i+1,0);
            ret.push_back(tmp);
        }
        for(int i = 0; i < numRows; i++) {
            ret[i][i] = ret[i][0] = 1;
        }
        for(int i = 0; i < numRows; i++) {
            for(int j = 1; j < i; j++) {
                ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
            }
        }
        return ret;
    }
};