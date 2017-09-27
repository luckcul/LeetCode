class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> links(numCourses, vector<int>());
        vector<int> in(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++) {
            pair<int, int> p = prerequisites[i];
            in[p.first] ++;
            links[p.second].push_back(p.first);
        }
        queue<int> Q;
        int finishCourses = 0;
        for(int i = 0; i < numCourses; i++) {
            if(in[i] == 0) Q.push(i);
        }
        while(!Q.empty()) {
            int now = Q.front();
            finishCourses ++; 
            Q.pop();
            for(int i = 0; i < links[now].size(); i++) {
                int next = links[now][i];
                in[next] --; 
                if(in[next] <= 0) {
                    Q.push(next);
                }
            }
        }
        return finishCourses >= numCourses;
    }
};