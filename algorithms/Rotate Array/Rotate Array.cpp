class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); 
        k %= n;
        if(k == 0) return ;
        int cycle = gcd(n, k);
        for(int i = 0; i < cycle; i++) {
            int now_index = i, now_val = nums[now_index];
            int count = 0; 
            int upper = n/cycle;
            while(count < upper) {
                now_index = (now_index + k) % n;
                int next_val = nums[now_index];
                nums[now_index] = now_val;
                now_val = next_val;
                count ++;
            }
        }
    }
    int gcd(int a, int b) {
        if(!b) return a;
        if(a < b) return gcd(b, a); 
        return gcd(b, a%b);
    }
};