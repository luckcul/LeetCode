class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int len = stoneValue.size(); 
        reverse(stoneValue.begin(), stoneValue.end()); 
        
        vector<int> dp(len+1, 0); 
        vector<int> sel(len+1, 0); 
        for(int i = 1; i <= len; i++) {
            int now_v = stoneValue[i-1]; 
            int max_v = -1123456; 
            int max_diff = -1123456;
            int max_j; 
            int sum_v = 0; 
            
            for(int j = 0; j < 3; j++) {
                if(i-j-1 < 0) break; 
                sum_v += stoneValue[i-j-1]; 
                int temp_v = sum_v; 
                
                int op_max_value = dp[i-j-1]; 
                int my_last_pos = i-j-1-sel[i-j-1]-1; 
                if(my_last_pos>0) {
                    temp_v += dp[my_last_pos]; 
                }
                if(temp_v - op_max_value >= max_diff) {
                    max_diff = temp_v - op_max_value; 
                    max_v = temp_v; 
                    max_j = j; 
                }
            }
            dp[i] = max_v; 
            sel[i] = max_j; 
        }
        int a_score = dp[len]; 
        int b_score = dp[len-1-sel[len]];
        if(a_score>b_score) return "Alice"; 
        else if(a_score < b_score) return "Bob"; 
        return "Tie";
    }
};