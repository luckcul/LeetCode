class Solution {
public:
    int numSteps(string s) {
        int len = s.size(); 
        int ret = 0; 
        int start = 0; 
        int i = len-1; 
        while( (i >= 1 && start==0) || (i>=0 && start==1)) {
            // cout<<i<<", "<<s[i]<<endl;
            if(s[i] == '0') {
                ret ++; 
                i--; 
            }
            else {
                int last = 1; 
                for(int j = i; j >=0; j--) {
                    if(last == 0) break; 
                    if(s[j] == '1') {
                        s[j] = '0'; 
                        last = 1; 
                    }
                    else {
                        s[j] = '1'; 
                        last = 0; 
                    }
                }
                start = last; 
                ret ++; 
            }
        }
        return ret; 
    }
};