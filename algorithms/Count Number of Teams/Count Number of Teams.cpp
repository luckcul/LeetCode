class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ret = 0; 
        int n = rating.size(); 
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                for(int k = j+1; k < n; k++) {
                    if(rating[i] < rating[j] && rating[j] < rating[k]) ret ++; 
                    if(rating[i] > rating[j] && rating[j] > rating[k]) ret ++; 
                }
            }
        }
        return ret; 
    }
};