class Solution {
public:
    string makeGood(string s) {
        string tmp = s; 
        while(true) {
            int len = tmp.size(); 
            string newtmp; 
            bool flag = true; 
            for(int i = 0; i < len-1; i++) {
                if(tmp[i] - tmp[i+1] == 'A'-'a' || tmp[i] - tmp[i+1] == 'a'-'A') {
                    flag = false; 
                    cout<<tmp.substr(0, i)<<endl;
                    newtmp = tmp.substr(0, i) + tmp.substr(i+2, len-i-2); 
                    i++; 
                }
            }
            
            if(flag) break;
            tmp = newtmp; 
        }
        return tmp; 
    }
};