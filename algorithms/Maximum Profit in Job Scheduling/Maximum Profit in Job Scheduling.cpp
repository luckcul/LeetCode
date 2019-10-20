class Solution {
    struct node {
        int s, e, p; 
        node(int x, int y, int z): s(x), e(y), p(z) {}
    }; 
    static bool cmp(node x, node y) {
        if(x.e == y.e) return x.s<y.s; 
        return x.e < y.e; 
    }
    int find(vector<node> &task, int val, int len) {
        int l = 0; 
        int r = len-1; 
        int ret = -1; 
        while(l <= r) {
            int m = (l+r)/2; 
            int tmp = task[m].e; 
            if(tmp <= val) {
                ret = m; 
                l = m+1; 
            }
            else r = m-1; 
        }
        return ret+1; 
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int len = startTime.size(); 
        vector<node> task; 
        for(int i = 0; i< len; i++) {
            task.push_back(node(startTime[i], endTime[i], profit[i])); 
        }
        cout<<"ok1"<<endl;
        sort(task.begin(), task.end(), cmp); 
        vector<int> last_idx(len+1, 0); 
        for(int i = 1; i < len; i++) {
            int last_i = find(task, task[i].s, len); 
            last_idx[i] = last_i; 
        }
        cout<<"ok2"<<endl;
        vector<int> dp(len+1, 0); 
        for(int i = 0; i < len; i++) {
            dp[i+1] = max(dp[i], task[i].p + dp[last_idx[i]]); 
        }
        cout<<"ok3"<<endl;
        return dp[len]; 
    }
};