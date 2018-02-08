#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std; 

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int len = num.size(); 
        // cout<<len<<endl;
        for(int i = 1; i < len; i++) {
            for(int j = 1; i+j <= len; j++) {
                if(check(num, i, j)) return true; 
            }
        }
        return false; 
    }
    bool check(string &num, int len1, int len2) {
        int s1 = 0, s2 = len1; 
        if(len1 >= 2 && num[s1] == '0') return false; 
        if(len2 >= 2 && num[s2] == '0') return false; 
        // cout<<"\n"<<num.substr(s1, len1)<<" "<<num.substr(s2, len2)<<" ";
        while(1) {
            string ans = add(num.substr(s1, len1), num.substr(s2, len2)); 
            int len3 = ans.size(); 
            // cout<<ans<<" ";
            if(s2+len2+len3 > num.size()) return false; 
            if(ans == num.substr(s2+len2, len3)) {
                s1 = s2; len1 = len2;
                s2 = s2+len2; len2 = len3;
                if(s2+len2 == num.size()) return true; 
            }
            else return false; 
        }
        return false; 
    }
    string add(string s1, string s2) {
        string ret = ""; 
        int i = s1.size()-1, j = s2.size()-1; 
        int last = 0; 
        while(i >= 0 && j >= 0) {
            int val = last + (s1[i] - '0') + (s2[j] - '0'); 
            ret += ('0' + val%10); 
            last = val / 10; 
            j--; i--; 
        }
        while(i >= 0) {
            int val = last + (s1[i]-'0'); 
            ret += ('0' + val%10); 
            last = val / 10;  
            i--; 
        }
        while(j >= 0) {
            int val = last + (s2[j] - '0'); 
            ret += ('0' + val %10); 
            last = val/10; 
            j--; 
        }
        if(last) ret += ('0' + last); 
        reverse(ret.begin(), ret.end()); 
        return ret; 
    }
};

int main(){
    Solution s;
    cout<<s.isAdditiveNumber("199100199");
    return 0; 
}