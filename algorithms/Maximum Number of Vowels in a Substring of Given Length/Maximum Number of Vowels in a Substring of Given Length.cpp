class Solution {
public:
    int maxVowels(string s, int k) {
        int len = s.size(); 
        string vowels = "aeiou"; 
        int ret = 0; 
        int tmp = 0; 
        for(int i = 0; i < len; i++) {
            bool f = false; 
            for(int j = 0; j < 5; j++) {
                if(s[i] == vowels[j]) {
                    f = true; 
                    break;
                }
            }
            if(f) {
                tmp ++; 
            }
            if(i-k >= 0) {
                f = false; 
                for(int j = 0; j < 5; j++) {
                    if(s[i-k] == vowels[j]) {
                        f = true; 
                        break;
                    }
                }
                if(f) tmp--; 
            }
            ret = max(ret, tmp); 
        }
        return ret; 
    }
};