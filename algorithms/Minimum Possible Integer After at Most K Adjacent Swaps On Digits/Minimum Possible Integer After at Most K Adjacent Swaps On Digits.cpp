const int MAXN = 31234;
vector<int> pos[15];
int sum[MAXN], cur[15], n;

int lowbit(int x){ return x & -x; }
void add(int x, int v){
    for (int i = x; i <= n; i += lowbit(i)) sum[i] += v;
}
int get(int x){
    int ret = 0;
    for (int i = x; i>0; i -= lowbit(i)) ret += sum[i];
    return ret;
}

class Solution {
public: 
    string minInteger(string num, int k) {
        n = num.length(); 
        for(int i = 0; i <= n; i++) sum[i] = 0; 
        for(int i = 0; i < 10; i++) {
            pos[i].clear(); 
            cur[i] = 0; 
        }
        for(int i = 0; i < n; i++) {
            pos[num[i] - '0'].push_back(i+1); 
        }
        string ret = ""; 
        for(int i = 1; i <= n; i++) {
            // cout<<ret<<endl;
            for(int dig = 0; dig < 10; dig++) {
                if(cur[dig] >= pos[dig].size()) continue; 
                int idx = pos[dig][cur[dig]]; 
                int step = idx - get(idx) - 1; 
                // cout<<dig<<" "<<k<<","<<step<<endl;
                if(step <= k) {
                    k -= step; 
                    ret += char('0' + dig); 
                    add(idx, 1); 
                    cur[dig] ++; 
                    break;
                }
            }
        }
        return ret; 
    }
};