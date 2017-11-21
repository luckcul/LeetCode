class Solution {
    double eps = 0.000001;
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, int> M; 
        int count_s = 0; 
        int length_equ = equations.size(); 
        for(int i = 0; i < length_equ; i++) {
            if(M.find(equations[i].first) == M.end()) {
                count_s ++;
                M[equations[i].first] = count_s;
            }
            if(M.find(equations[i].second) == M.end()) {
                count_s ++;
                M[equations[i].second] = count_s;
            }
        }
        vector<vector<double>> mat(count_s + 1, vector<double>(count_s + 1, 0));
        for(int i = 0; i < length_equ; i++) {
            int s = M[equations[i].first];
            int e = M[equations[i].second];
            // cout<<s<<" "<<e<<" "<<values[i]<<endl;
            // cout<<e<<" "<<s<<" "<<1.0/ values[i]<<endl;
            mat[s][e] = values[i];
            mat[e][s] = 1.0 / values[i];
        }
        for(int i = 1; i <= count_s; i++) mat[i][i] = 1.0;
        for(int k = 1; k <= count_s; k++) {
            for(int i = 1; i <= count_s; i++) {
                for(int j = 1; j <= count_s; j++) {
                    if(mat[i][j] >= eps) continue;
                    if(mat[i][k] >= eps && mat[k][j] >= eps) mat[i][j] = mat[i][k] * mat[k][j];
                }
            }
        }
        vector<double> ret;
        for(int i = 0; i < queries.size(); i++) {
            int s = -1, e = -1; 
            if(M.find(queries[i].first) != M.end()) s = M[queries[i].first];
            if(M.find(queries[i].second) != M.end()) e = M[queries[i].second];
            // cout<<s<<" "<<e<<endl;
            if(s == -1 || e == -1) {
                ret.push_back(-1.0); continue;
            }
            if(mat[s][e] < eps) ret.push_back(-1.0);
            else ret.push_back(mat[s][e]);
            // cout<<mat[s][e]<<endl;
        }
        return ret;
    }
};