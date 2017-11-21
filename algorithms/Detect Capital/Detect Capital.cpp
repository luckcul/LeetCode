class Solution {
public:
    bool detectCapitalUse(string word) {
        int lower = 0, upper = 0; 
        bool first_upper = true;
        if(word[0] >= 'a') first_upper = false;
        for(int i = 0; i < word.size(); i++) {
            if(word[i] >= 'a') lower++;
            else upper++;
        }
        if(first_upper && upper <= 1) return true;
        if(!upper || !lower) return true;
        return false;
    }
};