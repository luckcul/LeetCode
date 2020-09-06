class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int len = s.size(); 
        int sum = cost[0]; 
        int max_value = cost[0]; 
        int ret = 0; 
        for(int i = 1; i <= len; i++) {
            if(i==len || s[i]!= s[i-1]) {
                ret += sum-max_value; 
                if(i < len) {
                sum = cost[i]; 
                max_value=cost[i]; 
                }
            }
            else {
                max_value = max(max_value, cost[i]); 
                sum += cost[i]; 
            }
        }
        return ret; 
    }
};