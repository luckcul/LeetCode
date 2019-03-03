class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        int len_lamps = lamps.size(); 
        int len_ques = queries.size(); 
        vector<int> ok_lamps(len_lamps, 1); 
        vector<int> ret; 
        for(int i = 0; i < len_ques; i++) {
            int xi = queries[i][0];
            int yi = queries[i][1]; 
            int flag = 0; 
            for(int j = 0; j < len_lamps; j++) {
                if(!ok_lamps[j]) continue; 
                if(xi == lamps[j][0]) flag = 1; 
                if(yi == lamps[j][1]) flag = 1;
                int dx = abs(xi - lamps[j][0]); 
                int dy = abs(yi - lamps[j][1]); 
                if(dx == dy) flag = 1; 
                if(dx <= 1 && dy <= 1) ok_lamps[j] = 0; 
            }
            ret.push_back(flag); 
        }
        return ret; 
    }
};