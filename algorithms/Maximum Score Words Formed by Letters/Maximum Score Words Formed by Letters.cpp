class Solution {
public:
    bool check(int bits, vector<string>& words, vector<int> &letter_count, int n) {
        vector<int> count(30, 0); 
        for(int i = 0; i < n; i++) {
            if(bits&(1<<i)) {
                for(int j = 0; j < words[i].size(); j++) {
                    count[words[i][j]-'a']++; 
                }
            }
        }
        for(int i = 0; i <= 'z'-'a'; i++) {
            if(count[i] > letter_count[i]) return false; 
        }
        return true; 
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int ret = 0; 
        int len = words.size(); 
        vector<int> vals; 
        for(int i = 0; i < len; i++) {
            int v = 0; 
            for(int j = 0; j < words[i].size(); j++) {
                char ch = words[i][j]; 
                v += score[ch-'a'];
            }
            vals.push_back(v); 
        }
        
        vector<int> letter_count(30, 0); 
        for(int i = 0; i < letters.size(); i++) {
            letter_count[letters[i]-'a']++; 
        }
        
        for(int i = 0; i <= (1<<len)-1; i++) {
            bool b = check(i, words, letter_count, len); 
            if(!b) continue; 
            int temp_sum = 0; 
            for(int j = 0; j < len; j++) {
                if(i&(1<<j)) {
                    temp_sum += vals[j];
                }
            }
            ret = max(ret, temp_sum); 
        }
        return ret; 
    }
};