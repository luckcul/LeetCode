class Solution {
    void dfs(string digits, int length, vector<string> &ret, string str[], int index, string nowStr) {
        if(index == length) {
            if(nowStr.size()) ret.push_back(nowStr);
            return ;
        }
        int dig = digits[index] - '0';
        for(int i = 0; i < str[dig].size(); i++){
            dfs(digits, length, ret, str, index+1, nowStr + str[dig][i]);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string str[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ret;
        int length = digits.size(); 
        dfs(digits, length, ret, str, 0, "");
        return ret;
    }
};