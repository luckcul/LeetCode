class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int last = 1;
        for(int i = digits.size() - 1; i >= 0; i--) {
            digits[i] += last;
            last = digits[i] / 10; 
            digits[i] %= 10; 
            if(!last) break;
        }
        if(last) {
            digits.insert(digits.begin(), last);
        }
        return digits;
    }
};