class Solution {
    int* next; 
public:
    void get_next(string &s) {
        int len = s.size();
        // next = vector<int>(len+1, 0); 
        next = new int[len+1];
        if(len < 1) return;
        next[0] = -1; 
        int j = 0, k = -1; 
        while(j < len) {
            if(k == -1 || s[j] == s[k]) {
                j++; k++; 
                next[j] = k;
            }
            else k = next[k];
        }
    }
    int kmp(string &s1, string &s2) {
        int len1 = s1.size();
        int len2 = s2.size(); 
        // if(len1 < 1 && len2 < 1) return 0;
        if(len2 < 1) return 0;
        get_next(s2); 
        int i = 0, j = 0;
        while(i < len1){
            if(j == -1 || s1[i] == s2[j]) {
                i++; j++;
            }
            else j = next[j]; 
            
            if(j == len2) return i-len2;
        }
        return -1;
    }

    int strStr(string haystack, string needle) {
        return kmp(haystack, needle);
    }
};