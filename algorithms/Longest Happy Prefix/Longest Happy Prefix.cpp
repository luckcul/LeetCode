class Solution {
public:
    int next[100005] ;
     
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

    string longestPrefix(string s) {
        int len = strlen(s.c_str()) ;
        getNext(s.c_str());
        string ret = ""; 
        for(int i = len-next[len-1]; i < len; i++) ret += s[i]; 
        return ret; 
    }
};