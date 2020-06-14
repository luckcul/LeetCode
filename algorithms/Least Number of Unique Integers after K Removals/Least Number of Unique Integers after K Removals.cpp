class Solution {
    struct node {
        int val;
        int cnt; 
    };
public:
    static bool cmp(node &x, node &y) {
        if(x.cnt==y.cnt) return x.val>y.val; 
        return x.cnt < y.cnt; 
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int len = arr.size(); 
        unordered_map<int, int> M; 
        for(int i = 0; i < len; i++) {
            if(M.find(arr[i]) == M.end()) {
                M[arr[i]] = 1; 
            }
            else {
                M[arr[i]] ++; 
            }
        }
        vector<node> p; 
        for(unordered_map<int, int>::iterator it = M.begin(); it != M.end(); it++) {
            int val = it->first; 
            int cnt = it->second; 
            node t; 
            t.val = val; 
            t.cnt = cnt; 
            p.push_back(t); 
        }
        sort(p.begin(), p.end(), cmp); 
        int p_len = p.size(); 
        int idx = 0; 
        for(idx = 0; idx < p_len; idx++) {
            if(p[idx].cnt <= k) {
                k -= p[idx].cnt; 
            }
            else {
                break;
            }
        }
        return p_len-idx;
    }
};