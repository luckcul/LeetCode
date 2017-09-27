class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(); 
        if(n == 0) return false;
        int m = matrix[0].size();
        if(m == 0) return false;
        int lastIndex = m - 1;
        for(int i = 0; i < n; i++) {
            while(lastIndex >= 0 && matrix[i][lastIndex] > target) lastIndex --;
            if(lastIndex < 0) return false;
            if(matrix[i][lastIndex] == target) return true;
        }
        return false;
    }
};