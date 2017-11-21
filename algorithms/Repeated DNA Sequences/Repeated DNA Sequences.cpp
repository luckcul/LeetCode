class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int length = s.size(); 
        vector<string> ret; 
        if(length < 10) return ret;
        vector<int> rep(length, 0); 
        for(int i = 0; i < length; i++) {
            if(s[i] == 'A') rep[i] = 0;
            else if(s[i] == 'T') rep[i] = 1;
            else if(s[i] == 'G') rep[i] = 2; 
            else if(s[i] == 'C') rep[i] = 3;
        }
        unordered_map<int, int> M;
        int sta = 0, i = 0; 
        while(i < 9){
            sta<<=2; sta |= rep[i]; i++;
        }
        for(; i < length; i++) {
            sta <<= 2; sta &= 0xfffff;
            sta |= rep[i]; 
            M[sta]++; 
            if(M[sta] == 2) ret.push_back(s.substr(i-9, 10));
        }
        return ret;
    }
};