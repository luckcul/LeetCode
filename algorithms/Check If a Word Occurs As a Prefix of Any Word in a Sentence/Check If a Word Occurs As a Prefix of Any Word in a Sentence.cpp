class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int new_word = 1; 
        int idx = 1; 
        int idx_s = 0; 
        int conti = 1; 
        int len_s = searchWord.size(); 
        for(int i = 0; i < sentence.size(); i++) {
            if(sentence[i] == ' ') {
                idx++; 
                new_word = 1; 
                conti = 1; 
                idx_s = 0; 
                continue; 
            }
            if(sentence[i] == searchWord[idx_s] && conti) {
                idx_s ++; 
            }
            else {
                conti = 0; 
            }
            if(idx_s == len_s) {
                return idx; 
            }
        }
        return -1; 
    }
};