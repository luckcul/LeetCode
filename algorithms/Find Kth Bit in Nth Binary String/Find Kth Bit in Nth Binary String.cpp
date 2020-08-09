class Solution {
public:
    char findKthBit(int n, int k) {
        string s="0"; 
        for(int i = 1; i < n; i++) {
            int len = s.size(); 
            string tmp; 
            tmp = s; 
            tmp += "1"; 
            for(int j = len-1; j>=0; j--) {
                if(s[j] == '0') tmp += "1"; 
                else tmp += "0"; 
            }
            s = tmp; 
        }
        return s[k-1]; 
    }
};