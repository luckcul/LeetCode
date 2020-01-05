
class Solution {
public:
    static int cmp(pair<string, int> &a, pair<string, int> &b) {
        if(a.second!=b.second) return a.second<b.second; 
        return a.first<b.first;
    }
    vector<int> bfs(int now_idx, vector<vector<int>>& friends,  vector<int> &vis, vector<int> &level_v, int level) {
        vector<int> v[2]; 
        int now_v = 0;
        v[now_v].push_back(now_idx); 
        int now_l = 0; 
        
        while(now_l+1 <= level) {
            int next_v = 1-now_v; 
            for(int i = 0; i < v[now_v].size(); i++) {
                int nodei = v[now_v][i]; 
                for(int j = 0; j < friends[nodei].size(); j++) {
                    int next_node = friends[nodei][j]; 
                    if(vis[next_node]) continue; 
                    v[next_v].push_back(next_node); 
                    vis[next_node] = 1; 
                }
            }
            v[now_v].clear(); 
            now_l ++; 
            now_v = next_v; 
        }
        return v[now_v]; 
    }
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size(); 
        vector<int> level_v; 
        vector<int> vis(n, 0); 
        vis[id] = 1; 
        vector<int> f = bfs(id, friends, vis, level_v, level); 
        //check
        for(int i = 0; i < f.size(); i++) {
            cout<<f[i]<<" ";
        }
        cout<<endl;
        unordered_map<string, int> M; 
        
        for(int i = 0; i < f.size(); i++) {
            int idx = f[i]; 
            for(int j = 0; j < watchedVideos[idx].size(); j++) {
                string video = watchedVideos[idx][j];
                unordered_map<string, int>::iterator it = M.find(video); 
                if(it == M.end()) {
                    M[video] = 1; 
                }
                else {
                    M[video] ++; 
                }
            }
        }
        vector<pair<string, int>> ret; 
        for(unordered_map<string, int>::iterator it=M.begin(); it!=M.end(); it++) {
            ret.push_back(make_pair(it->first, it->second));
            cout<<"pair "<<it->first<<" "<<it->second<<endl;
        }
        sort(ret.begin(), ret.end(), cmp); 
        vector<string> ans; 
        for(int i = 0; i < ret.size(); i++) {
            ans.push_back(ret[i].first); 
        }
        return ans; 
    }
};