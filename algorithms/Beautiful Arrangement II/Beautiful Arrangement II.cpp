class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ret;
        ret.push_back(1);
        int interval = n-1, mul = 1;
        int mi = 1, ma = n+1;
        for(int x = 2; x <= k; x++) {
            int num = ret[ret.size()-1] + mul * interval;
            ret.push_back(num);
            if(num <= (n+1)/2) mi = max(mi, num);
            else ma = min(ma, num);
            interval --; 
            mul *= -1;
        }
        if(ret[ret.size()-1] == mi) for(int i = mi + 1; i < ma; i++) ret.push_back(i); 
        else for(int i = ma-1; i > mi; i--) ret.push_back(i);
        return ret;

    }
};