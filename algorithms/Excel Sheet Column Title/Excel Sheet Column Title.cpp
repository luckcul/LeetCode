#include <cstdio>
#include <algorithm>
class Solution {
public:
    string convertToTitle(int n) {
        // if(n <= 26) return "" + ('A' + n - 1);
        // n --; 
        string ret = "";
        while(n) {
            int val = n % 26; 
            val = (val + 26 - 1) % 26 + 1;
            ret += 'A' + val - 1; 
            n = (n-1)/26;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

//   1 -> A
//     2 -> B
//     3 -> C
//     ...
//     26 -> Z
//     27 -> AA
//     28 -> AB 
