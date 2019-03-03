class Solution {
    int find(vector<int> &par, int x) {
        if(par[x] == -1) return x; 
        return par[x] = find(par, par[x]);
    }
public:
    bool equationsPossible(vector<string>& equations) {
        int len = equations.size(); 
        vector<int> par(30, -1); 
        
        for(int i = 0; i < len; i++) {
            int a = equations[i][0] - 'a'; 
            int b = equations[i][3] - 'a'; 
            bool equ = equations[i][1] == '=';
            int par_a = find(par, a); 
            int par_b = find(par, b); 
            if(equ) {
                if(par_a != par_b) par[par_a] = par_b; 
            }
        for(int i = 0; i < len; i++) {
            int a = equations[i][0] - 'a'; 
            int b = equations[i][3] - 'a'; 
            bool equ = equations[i][1] == '=';
            int par_a = find(par, a); 
            int par_b = find(par, b); 
            if(!equ) {
                if(par_a == par_b) return false;
            }
        }
        return true; 
    }
};