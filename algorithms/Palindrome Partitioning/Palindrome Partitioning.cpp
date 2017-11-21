class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret; 
        int n = s.size(); 
        vector<vector<int>> mark(n, vector<int>());
        for(int i = 0; i < n; i++) {
            int add = 0;
            while(i - add >= 0 && i + add < n && s[i-add] == s[i+add]) {
                mark[i-add].push_back(i+add);
                add ++;
            }
            add = 0;
            while(i - add >= 0 && i+add+1 < n && s[i-add] == s[i+add + 1]) {
                mark[i-add].push_back(i+add+1); add++;
            }
        }
        vector<string> temp;
        dfs(ret, temp, mark, 0, n, s);
        return ret;
    }
    void dfs(vector<vector<string>> &ret, vector<string> &temp, vector<vector<int>> &mark, int index, int upper, string &s){
        if(index >= upper) {
            vector<string> ret_;
            copy(temp.begin(), temp.end(), back_inserter(ret_));
            ret.push_back(ret_);
            return ;
        }
        for(int i = 0; i < mark[index].size(); i++) {
            int next_index = mark[index][i];
            temp.push_back(s.substr(index, next_index - index + 1));
            dfs(ret, temp, mark, next_index + 1, upper, s);
            temp.pop_back();
        }
    }
};