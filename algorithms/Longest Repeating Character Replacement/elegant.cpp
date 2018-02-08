class Solution {
public:
    int characterReplacement(string s, int k) {
        int ret = 0; 
        int len = s.size(); 
        int cnt[30] = {};
        int j = 0, i = 0;
        while(i < len) {
            cnt[s[i] - 'A'] ++; 
            int need = i-j+1 - *max_element(cnt, cnt+26); 
            if(need <= k) ret = max(ret, i-j+1); 
            else {
                cnt[s[j] - 'A']--; 
                j++; 
            }
            i++; 
        }

        return ret;         
    }
};