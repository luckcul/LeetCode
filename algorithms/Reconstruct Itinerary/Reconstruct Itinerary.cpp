class Solution {
    unordered_map<string, multiset<string>> M;
    vector<string> ret; 
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        // JFK
        for(int i = 0; i < tickets.size(); i++) {
            string s = tickets[i].first;
            string e = tickets[i].second;
            M[s].insert(e);
        }
        string now = "JFK";
        dfs(now);
        
        return vector<string>(ret.rbegin(), ret.rend());
    }
    void dfs(string now) {
        while(M.find(now) != M.end() && M[now].size() != 0) {
            string e = *M[now].begin();
            M[now].erase(M[now].begin());
            dfs(e);
        }
        ret.push_back(now);
    }
};