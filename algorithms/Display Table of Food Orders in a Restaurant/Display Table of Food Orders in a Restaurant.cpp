class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        int len_ord = orders.size(); 
        set<string> s; 
        for(int i = 0; i < len_ord; i++) {
            s.insert(orders[i][2]); 
        }
        int food_size = s.size(); 
        vector<string> foods;
        unordered_map<string, int> map_foods; 
        int idx = 0; 
        for(set<string>::iterator it = s.begin(); it!=s.end(); it++) {
            foods.push_back(*it); 
            map_foods[*it] = idx++; 
            cout<<*it<<endl;
        }
        
        vector<vector<int>> p(501, vector<int>(food_size+1, 0)); 
        vector<int> vis(501, 0); 
        for(int i = 0; i < len_ord; i++) {
            string id = orders[i][1]; 
            int id_ = std::stoi(id); 
            vis[id_] = 1; 
            int food_id = map_foods[orders[i][2]]; 
            p[id_][food_id] ++; 
        }
        vector<vector<string>> ret; 
        vector<string> header; 
        header.push_back("Table"); 
        for(int i = 0; i < food_size; i++) {
            header.push_back(foods[i]); 
        }
        ret.push_back(header); 
        for(int i = 1; i < 501; i++) {
            if(!vis[i]) continue; 
            vector<string> pi; 
            pi.push_back(std::to_string(i)); 
            for(int j = 0; j < food_size; j++) {
                int cnt = p[i][j]; 
                pi.push_back(std::to_string(cnt)); 
            }
            ret.push_back(pi); 
        }
        return ret; 
    }
};