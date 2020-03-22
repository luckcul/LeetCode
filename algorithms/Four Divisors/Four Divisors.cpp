class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int max_v = 100001;
        vector<int> div_num(max_v, 0); 
        vector<int> div_sum(max_v, 0); 
        for(int i = 1; i < max_v; i++) {
            div_num[i] += 1; 
            div_sum[i] += i; 
        }
        for(int i = 2; i < max_v; i++) {
            div_num[i] += 1; 
            div_sum[i] += 1; 
        }
        for(int i = 2; i < max_v; i++) {
            for(int j = i+i; j < max_v; j+=i) {
                div_num[j] += 1; 
                div_sum[j] += i;
            }
        }
        int ret = 0; 
        for(int i = 0; i < nums.size(); i++) {
            // cout<<div_num[nums[i]]<<endl;
            if(div_num[nums[i]] == 4) {
                ret += div_sum[nums[i]]; 
            }
        }
        return ret; 
    }
};