class Solution {
public:
    vector<long long> get_bits(long long num) {
        // if(num < 0) num = 0;
        vector<long long> ret; 
        long long  base = 1;
        num++;
        for(int i = 0; i < 31; i++) {
            long long total_i = (num / (base*2)) * base; 
            total_i += min(base, num - total_i*2);
            ret.push_back(total_i);
            base *= 2; 
        }
        return ret;
    }
    int rangeBitwiseAnd(int m, int n) {
        auto bits_m = get_bits(m-1); 
        auto bits_n = get_bits(n);
        int ret = 0, base = 1; 
        for(int i = 0; i < 31; i++) {
            cout<<bits_n[i]<<" "<<bits_m[i]<<endl;
            ret += base * (bits_n[i] - bits_m[i] > 0 ? 0:1);
            base *= 2;
        }
        return ret;
    }
};