class Solution {
    static bool cmp(vector<int>& a, const vector<int>& b){
        if(a[0] == b[0]) return a[1] > b[1]; 
	    return a[0] > b[0];
	}
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        sort(coordinates.begin(), coordinates.end(), cmp); 
        bool ret = true; 
        int len = coordinates.size(); 
        int diff_x = coordinates[1][0] - coordinates[0][0]; 
        int diff_y = coordinates[1][1] - coordinates[0][1]; 
        // cout<<diff_x<<endl;
        // cout<<diff_y<<endl;
        for(int i = 2; i < len; i++) {
            int dxi = coordinates[i][0] - coordinates[i-1][0]; 
            int dyi = coordinates[i][1] - coordinates[i-1][1]; 
            if(dxi == 0 && diff_x == 0) continue; 
            if(dyi == 0 && diff_y == 0) continue; 
            if(dyi == 0) {
                ret = false; break;
            }
            if(dxi*diff_y == dyi*diff_x) continue; 
            else {
                ret = false; break;
            }
        }
        return ret; 
    }
};