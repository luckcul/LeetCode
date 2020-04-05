class Solution {
    struct node {
        int cnt; 
        char ch; 
    }p[3]; 
    
public:
    static bool cmp(node &x, node &y) {
        return x.cnt>y.cnt; 
    }
    string longestDiverseString(int a, int b, int c) {
        p[0].cnt = a; p[0].ch = 'a'; 
        p[1].cnt = b; p[1].ch = 'b'; 
        p[2].cnt = c; p[2].ch = 'c'; 
        sort(p, p+3, cmp); 
        vector<int> va(101, 0); 
        vector<int> vb(101, 0); 
        int upper = (p[0].cnt/2 + (p[0].cnt % 2)); 
        int idx = 0; 
        int t_cnt = p[1].cnt; 
        // cout<<"upper : "<<upper<<endl;
        for(int i = 0; i < p[1].cnt; i++) {
            idx %= upper; 
            va[idx]++; 
            // cout<<"idx va"<<endl;
            idx ++; 
        }
        t_cnt = p[2].cnt; 
        for(int i = 0; i < p[2].cnt; i++) {
            idx %= upper; 
            vb[idx]++; 
            idx++; 
        }
        string ret = ""; 
        for(int i = 0; i < upper; i++) {
            if(i == upper-1 && p[0].cnt%2==1) {
                ret += p[0].ch; 
            }
            else {
                ret += p[0].ch;
                ret += p[0].ch; 
            }
            if(va[i] == 0 && vb[i] == 0) break; 
            for(int j = 0; j < va[i]; j++) ret += p[1].ch; 
            for(int j = 0; j < vb[i]; j++) ret += p[2].ch; 
        }
        return ret; 
    }
};