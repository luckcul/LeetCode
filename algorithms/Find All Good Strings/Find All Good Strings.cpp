class Solution {
    char s[512]; 
    char e[100]; 
    long long dp[505][55]; 
    long long mod = 1000000007; 
    
public:
    
    int next[100] ;
     
    void getNext( const char p[] )     {
        int len = strlen(p) ;
        next[0] = 0 ;
        int i = 0 , j = 0 ;
        for(j = 1 ; j < len ; j++) {
            while( p[i] != p[j] && i > 0  )  
                i = next[i-1] ;
            if(p[i] == p[j])    {
                i++ ; 
                next[j] = i ; 
            }
            else
                next[j] = 0 ;
        }
    }
    
    long long dfs(int i, int j, int flag, int n, int m, string &evil) {
        // cout<<i<<", "<<j<<endl;
        if(i == 0) return 1; 
        if(!flag && dp[i][j]!=-1) return (dp[i][j]+mod)%mod; 
        int bound = flag ? s[i]-'a' : 'z'-'a'; 
        long long ret = 0; 
        for(int x = 0; x <= bound; x++) {
            int next_j = 0;
            if(evil[j]-'a' == x) {
                next_j = j+1; 
            } 
            else {
                if(j == 0) next_j=0; 
                else next_j = next[j-1]; 
                while(next_j && evil[next_j]-'a' != x) {
                    next_j = next[next_j-1]; 
                }
                if(evil[next_j]-'a' == x) next_j++; 
            }
            if(next_j == m) continue; 
            ret += dfs(i-1, next_j, flag? x==bound:0, n, m, evil); 
            ret %= mod; 
        }
        ret %= mod; 
        return flag ? ret:dp[i][j] = ret; 
    }
    
    int findGoodStrings(int n, string s1, string s2, string evil) {
        
        // int len = strlen(evil.c_str()) ;
        getNext(evil.c_str());
        for(int i = 0; i < evil.size(); i++) cout<<next[i]<<", "; 
        cout<<endl;
        
        memset(dp, -1, sizeof(dp)); 
        int len2 = evil.size(); 
        for(int i = 0; i < n; i++) {
            s[n-i] = s1[i]; 
        }
        long long tmp1 = dfs(n, 0, 1, n, len2, evil); 
        cout<<"----------"<<tmp1<<endl;
        memset(dp, -1, sizeof(dp)); 
        for(int i = 0; i < n; i++) {
            s[n-i] = s2[i]; 
        }
        long long tmp2 = dfs(n, 0, 1, n, len2, evil); 
        cout<<"----------"<<tmp2<<endl;
        
        int c = 1; 
        for(int i = 0; i <= n-len2; i++) {
            if(s1.substr(i, len2) == evil) {
                c = 0; 
                break;
            }
        }
        cout<<c<<endl;
        return (tmp2+c+mod-tmp1)%mod; 
    }
};