
class Solution {
public:
    int findKthNumber(int n, int k) {
        vector<int> n_digs; 
        int n_ = n; 
        while(n_) {
            n_digs.push_back(n_ % 10); 
            n_ /= 10; 
        }
        reverse(n_digs.begin(), n_digs.end());
        bool first = true;
        vector<int> ret; 
        // k --;
        while(true) {
            ret.push_back(0);
            int nowLength = ret.size();
            int sum_s = 0, last_sum_s = 0; 
            int dig_i = 0;
            if(first) dig_i = 1, first = false;
            for(; dig_i <= 9; dig_i++) {
                ret[nowLength - 1] = dig_i;
                int s = count_start_with(ret, n_digs, n);
                last_sum_s = sum_s;
                sum_s += s; 
                if(sum_s >= k) {
                    break;
                }
            }
            k -= last_sum_s;
            k --;
            if(k  <= 0) break;
        }
        int ret_ = 0; 
        for(int i = 0; i < ret.size(); i++) ret_ *= 10, ret_ += ret[i];
        return ret_;
    }
    int count_start_with(vector<int> &starts, vector<int> &n_digs, int n) {
        int n_length = n_digs.size();
        int s_length = starts.size();
        int starts_num = 0; 
        for(int i = 0; i < s_length; i++) starts_num *= 10, starts_num += starts[i];
        int status = 0; 
        for(int i = 0; i < s_length; i++) {
            if(starts[i] > n_digs[i]) {
                status = 1; break;
            }
            if(starts[i] < n_digs[i]) {
                status = 2; break;
            }
        }
        int ret = 1, base = 1; 
        for(int i = 1; i <= n_length - s_length; i++) {
            base *= 10; 
            starts_num *= 10;
            if(i != n_length - s_length) {
                ret += base;
            }
            else {
                if(status == 1) continue;
                else if(status == 2) ret += base;
                else ret += (n - starts_num+1);
            }
        }
        return ret;
    }
};
