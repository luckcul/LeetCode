class Solution {
public:
    int characterReplacement(string s, int k) {
        int ret = 0; 
        int len = s.size(); 
        for(char ch = 'A'; ch <= 'Z'; ch++) {
            int index = 0; 
            int cnt_not_ch = 0; 
            int last = -1; 
            queue<int> q; 
            q.push(-1); 
            while(index < len && cnt_not_ch < k) {
                if(s[index] != ch) {
                    q.push(index); 
                    cnt_not_ch ++; 
                }
                index++; 
            }
            // ret = max(ret, index); 
            while(index < len) {
                if(s[index] != ch) {
                    ret = max(ret, index - q.front()-1); 
                    q.pop(); q.push(index); 
                }
                index++; 
            }
            ret = max(ret, index - q.front()-1); 
        }
        return ret;         
    }
};