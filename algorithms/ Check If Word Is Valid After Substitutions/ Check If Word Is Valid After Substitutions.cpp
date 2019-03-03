class Solution {
    bool sol(string &S, int left_nums) {
        // cout<<S<<endl;
        int len = S.size(); 
        if(left_nums == 0) return true; 
        int flag = 0; 
        int idx = -1; 
        for(int i = 0;i < len; i++) {
            if(S[i] == '0') {
                continue;
            }
            if(S[i] == 'a') {
                flag = 1; 
            }
            else if(S[i] == 'b') {
                flag = (flag == 1? 2:0);
            }
            else {
                flag = (flag == 2? 3:0);
            }
            if(flag == 3) {
                idx = i; break;
            }
        }
        if(flag != 3) return false; 
        int cnt = 0; 
        for(int i = idx; i >= 0; i--) {
            if(cnt >= 3) break;
            if(S[i] == '0') continue; 
            S[i] = '0'; 
            cnt++; 
        }
        return sol(S, left_nums-3);
    }
public:
    bool isValid(string S) {
        // cout<<S<<endl;
        int len = S.size(); 
        if(len%3) return false; 
        return sol(S, len); 
    }
};