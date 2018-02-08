class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ret; 
        for(int i = 0; i < input.size(); i++) {
            if(input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> ret1 = diffWaysToCompute(input.substr(0, i));
                vector<int> ret2 = diffWaysToCompute(input.substr(i+1));
                for(int j = 0; j < ret1.size(); j++) {
                    for(int k = 0; k < ret2.size(); k++) {
                        if(input[i] == '+') ret.push_back(ret1[j] + ret2[k]);
                        else if(input[i] == '-') ret.push_back(ret1[j] - ret2[k]);
                        else ret.push_back(ret1[j] * ret2[k]);
                    }
                }
            }
        }
        if(ret.size() == 0) ret.push_back(to_int(input));
        return ret;
    }
    int to_int(string input) {
        int ret = 0; 
        for(int i = 0; i < input.size(); i++) ret *= 10, ret += input[i] - '0';
        return ret;
    }
};