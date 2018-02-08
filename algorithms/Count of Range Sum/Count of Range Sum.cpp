class Solution {
    vector<int> cnt; 
    int lowbit(int x) {
        return x & (-x); 
    }
    int get_sum(int i) {
        int ret = 0; 
        while(i > 0) {
            ret += cnt[i]; 
            i -= lowbit(i); 
        }
        return ret; 
    }
    void add(int i, int val) {
        while(i < cnt.size()) {
            cnt[i] += val; 
            i += lowbit(i); 
        }
    }
    int search_index(vector<long long> &sums, long long val, int len, bool equal) {
        int l = 1, r = len; 
        int ret = -1; 
        while(l <= r) {
            int m = (l + r) >> 1; 
            bool flag = equal ? sums[m] <= val : sums[m] < val; 
            if(flag) {
                ret = m; 
                l = m+1; 
            }
            else r = m-1; 
        }
        return ret; 
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int len = nums.size(); 
        if(len < 1) return 0; 
        vector<long long> sums(len+1, 0); 
        for(int i = 0; i < len; i++) {
            sums[i+1] = sums[i] + nums[i]; 
        }
        sort(sums.begin()+1, sums.end()); 
        // unordered_map<int, int> M; 
        // M[sums[1]] = 1; 
        int index = 2; 
        for(int i = 2; i <= len; i++) {
            if(sums[i] != sums[i-1]) {
                sums[index] = sums[i];
                index++; 
            }
        }
        cnt = vector<int>(index, 0); 
        long long s = 0; 
        int ret = 0; 
        for(int i = 0; i < len; i++) {
            s += nums[i]; 
            long long n_lower = s - upper; 
            long long n_upper = s - lower; 
            int idx_lower = search_index(sums, n_lower, index-1, false); 
            int idx_upper = search_index(sums, n_upper, index-1, true); 
            int idx_now = search_index(sums, s, index-1, true); 
            add(idx_now, 1); 
            ret += (idx_upper == -1? 0:get_sum(idx_upper)) - (idx_lower == -1? 0:get_sum(idx_lower)); 
            if(s >= (long long)lower && s <= (long long) upper) ret++; 
             
        }
        return ret; 

    }
};