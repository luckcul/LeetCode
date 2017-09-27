class Solution {
    struct node{
        int u, step;
    };
    int bfs(vector<vector<bool>> &mat, int start, int end) {
        vector<bool> vis(mat.size(), 0);
        vis[start] = true;
        node s; 
        s.u = start, s.step = 1;
        queue<node> Q;
        Q.push(s);
        while(!Q.empty()) {
            node now = Q.front();
            Q.pop();
            if(now.u == end) return now.step;
            for(int i = 0; i < mat.size(); i++) {
                if(vis[i]) continue;
                if(!mat[now.u][i]) continue;
                vis[i] = true;
                node next;
                next.u = i;
                next.step = now.step + 1;
                Q.push(next);
            }
        }
        return 0;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int length = wordList.size();
        wordList.push_back(beginWord);
        // wordList.push_back(endWord);
        int endIndex = -1;
        for(int i = 0; i < wordList.size(); i++) {
            if(wordList[i] == endWord) endIndex = i;
        }
        if(endIndex == -1) return 0;
        vector<vector<bool>> mat(wordList.size(), vector<bool>(wordList.size(), 0));
        for(int i = 0; i < wordList.size(); i++) {
            for(int j = i+1; j < wordList.size(); j++) {
                int diff = 0;
                for(int k = 0; k < wordList[i].size(); k++) {
                    diff += (wordList[i][k] != wordList[j][k]);
                }
                if(diff == 1) {
                    mat[i][j] = mat[j][i] = true;
                }
            }
        }
        int ret = bfs(mat, wordList.size()-1, endIndex);
        return ret;
    }
};