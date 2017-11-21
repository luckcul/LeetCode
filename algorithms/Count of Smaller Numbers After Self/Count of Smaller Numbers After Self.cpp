class Solution {
    vector<int> cnt;
    static bool cmp1(pair<int, int> x, pair<int, int> y) {
        return x.first < y.first;
    }
    static bool cmp2(pair<int, int> x, pair<int, int> y) {
        return x.second < y.second;
    }
    int lowbit(int x) {
        return x & (-x);
    }
    void update(int i) {
        while(i < cnt.size()) {
            cnt[i] += 1;
            i += lowbit(i);
        }
    }
    int get_sum(int i) {
        int ret = 0; 
        while(i > 0) {
            ret += cnt[i]; 
            i -= lowbit(i);
        }
        return ret;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int length = nums.size(); 
        vector<pair<int, int>> p; 
        for(int i = 0; i < length; i++) {
            p.push_back(make_pair(nums[i], i+1));
        }
        sort(p.begin(), p.end(), cmp1); 
        int last_val = 0;
        for(int i = 0; i < length; i++) {
            if(i != 0 && p[i].first == last_val) {
                last_val = p[i].first;
                p[i].first = p[i-1].first;
                continue;
            }
            last_val = p[i].first;
            p[i].first = i+1;
        }
        sort(p.begin(), p.end(), cmp2);
        cnt = vector<int>(length+1, 0);
        vector<int> ret(length, 0);
        for(int i = length - 1; i >= 0; i--) {
            int origin_index = p[i].first;
            // cout<<origin_index<<endl;
            ret[i] = get_sum(origin_index - 1);
            update(origin_index);
            // for(int j = 1; j <= 4; j ++) cout<<get_sum(j)<<" "; cout<<endl;
        }
        return ret;
    }
};