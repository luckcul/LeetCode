class Solution {
public: 
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        
        int i = 0, j = 0; 
        while(i < arr.size()) {
            int k = 0; 
            for(k= 0; k < pieces.size(); k++) {
                if(arr[i] == pieces[k][0]) {
                    break; 
                }
            }
            if(k>=pieces.size()) {
                return false; 
            }
            for(int f = 0; f < pieces[k].size(); f++) {
                if(arr[i] != pieces[k][f]) {
                    return false; 
                }
                i++; 
            }
            // i++; 
        }
        return true;  
    }
};