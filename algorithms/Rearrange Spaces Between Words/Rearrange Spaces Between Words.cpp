class Solution {
public:
    string reorderSpaces(string text) {
        string ret = ""; 
        int s_cnt = 0; 
        int w_cnt = 0; 
        int len = text.size(); 
        int last = -1; 
        for(int i = 0; i < len; i++) {
            if(text[i] == ' ') {
                s_cnt++; 
                if(i>0 && text[i-1] != ' ') {
                    w_cnt++; 
                }
            }
            else if(i==len-1) w_cnt++; 
        }
        int a = 0; 
        if(w_cnt>1) {
            a = s_cnt/(w_cnt-1); 
        }
        int b = s_cnt - a*(w_cnt-1); 
        cout<<s_cnt<<", "<<w_cnt<<endl;
        cout<<a<<", "<<b<<endl;
        int acc = 0; 
        for(int i = 0; i < len; i++) {
            if(text[i] != ' ') {
                ret += text[i]; 
                if(i+1<len && text[i+1]==' ' && acc < a*(w_cnt-1)) {
                    for(int j = 0; j < a; j++) {
                        ret += ' '; acc++; 
                    }
                }
//                 if(i==len-1 ) {
                    
//                 }
            }
        }for(int j = 0; j < b; j++) {
                        ret += ' '; 
                    }
        return ret; 
    }
};