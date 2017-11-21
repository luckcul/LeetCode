class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int length = s.size(); 
        string ret = "";
        for(int i = 0; i < numRows; i++) {
            vector<int> steps;
            steps.push_back(2*numRows - 2 - i*2);
            steps.push_back(2*numRows - 2 - steps[0]);
            int index = 1;
            for(int j = i; j < length; j += steps[index]){
                if(steps[index^1] == 0) {
                    index ^= 1;
                    continue;
                }
                ret.push_back(s[j]);
                index ^= 1;
            }
        }
        return ret;
    }
};