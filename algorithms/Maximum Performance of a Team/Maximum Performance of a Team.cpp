class Solution {
    struct node {
        int speed; 
        int efficiency; 
        node(int x, int y) : speed(x), efficiency(y) {}
        friend bool operator<(node x, node y) {
            return x.speed > y.speed;
        }
    };
private:
    static bool cmp(node x, node y) {
        if(x.efficiency == y.efficiency) return x.speed > y.speed; 
        return x.efficiency > y.efficiency; 
    }
    
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<node> p; 
        long long mod=1000000007;
        for(int i = 0; i < n; i++) {
            p.push_back(node(speed[i], efficiency[i])); 
        }
        sort(p.begin(), p.end(), cmp); 
        priority_queue<node> Q;
        long long sum = 0; 
        long long ret = 0; 
        // double sum_ = 0.0; 
        // double ret_ = 0.0; 
        
        for(int i = 0; i < n; i++) {
            int speed = p[i].speed; 
            int effic = p[i].efficiency; 
            // cout<<"for "<<i<<" : "<<speed<<", "<<effic<<endl;
            if(Q.size() >= k) {
                node tmp = Q.top(); 
                // cout<<"top "<<tmp.speed<<", "<<tmp.efficiency<<endl;
                if(tmp.speed < speed) {
                    Q.pop(); 
                    sum -= tmp.speed; 
                    // sum_ -= tmp.speed; 
                    Q.push(node(speed, effic)); 
                    sum += speed; 
                    // sum_ += speed; 
                }
            }
            else {
                Q.push(node(speed, effic)); 
                sum += speed; 
                // sum_
            } 
            // sum = (sum+mod) %mod; 
            // ret = max(ret, (sum*effic)%mod); 
            ret = max(ret, sum*effic); 
        }
        return ret%mod; 
        
        
//         int min_eff = 112345678; 
//         int max_eff = 0; 
//         for(int i = 0; i < n; i++) {
//             min_eff = min(min_eff, efficiency[i]); 
//             max_eff = max(max_eff, efficiency[i]); 
//         }
//         int l = min_eff; 
//         int r = max_eff; 
//         int ret = 0; 
//         while(l <= r) {
//             int m = (l+r)>>1; 
            
//         }
    }
};