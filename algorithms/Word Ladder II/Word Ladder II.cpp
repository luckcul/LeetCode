class Solution {
    struct node{
        int u, step;
    };
    void bfs(vector<vector<bool>> &mat, int start, int end, vector<vector<int>> &records) {
        vector<int> minSteps(mat.size(), 1e9);
        node s; 
        s.u = start, s.step = 1;
        queue<node> Q;
        Q.push(s);
        minSteps[start] = 1;
        records[start].push_back(-1);
        while(!Q.empty()) {
            node now = Q.front();
            Q.pop();
            for(int i = 0; i < mat.size(); i++) {
                if(minSteps[i] < now.step+1) continue;
                if(!mat[now.u][i]) continue;
                node next;
                next.u = i;
                next.step = now.step + 1;
                if(next.step < minSteps[next.u]){
                    minSteps[next.u] = next.step;
                    records[next.u].clear();
                    records[next.u].push_back(now.u);
                }
                else if(next.step == minSteps[next.u]) {
                    records[next.u].push_back(now.u);
                    continue;
                }
                Q.push(next);
            }
        }
    }
    void dfs(vector<vector<string>> &ret, vector<vector<int>> &records, int nowIndex, vector<string> path, vector<string>& wordList) {
        if(nowIndex == -1) {
            reverse(path.begin(), path.end());
            ret.push_back(path);
            return ;
        }
        path.push_back(wordList[nowIndex]);
        for(int i = 0; i < records[nowIndex].size(); i++) {
            int nextIndex = records[nowIndex][i];
            dfs(ret, records, nextIndex, path, wordList);
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ret;
        int length = wordList.size();
        wordList.push_back(beginWord);
        int endIndex = -1;
        for(int i = 0; i < wordList.size(); i++) {
            if(wordList[i] == endWord) endIndex = i;
        }
        if(endIndex == -1) return ret;
        vector<vector<bool>> mat(wordList.size(), vector<bool>(wordList.size(), 0));
        for(int i = 0; i < wordList.size(); i++) {
            for(int j = i+1; j < wordList.size(); j++) {
                int diff = 0;
                for(int k = 0; k < wordList[i].size(); k++) {
                    diff += (wordList[i][k] != wordList[j][k]);
                }
                if(diff == 1)  mat[i][j] = mat[j][i] = true; 
            }
        }
        vector<vector<int>> records(wordList.size(), vector<int>());
        bfs(mat, wordList.size()-1, endIndex, records);
        vector<string> startString;
        dfs(ret, records, endIndex, startString, wordList);
        return ret;
    }
};