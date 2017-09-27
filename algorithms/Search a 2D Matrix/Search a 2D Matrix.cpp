class Solution {

    int bs1(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int l = 0, r = n-1, ret = -1;
        while(l <= r) {
            int m = (l + r) >> 1; 
            if(matrix[m][0] <= target) {
                l = m + 1;
                ret = m;
            }
            else r = m -1;
        }
        return ret;
    }
    int bs2(vector<int> &vec, int target) {
        int n = vec.size(); 
        int l = 0, r = n - 1, ret = -1;
        while(l <= r) {
            int m = (l + r) >> 1;
            if(vec[m] == target) return m;
            else if(vec[m] > target) r = m - 1;
            else l = m + 1;
        }
        return ret;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0) return false;
        int m = matrix[0].size();
        if(m == 0) return false;
        int index1 = bs1(matrix, target);
        if(index1 == -1) return false;
        int index2 = bs2(matrix[index1], target);
        if(index2 == -1) return false;
        return matrix[index1][index2] == target;
    }
};