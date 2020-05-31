class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int hc = horizontalCuts.size(); 
        int vc = verticalCuts.size(); 
        long long mod = 1000000007; 
        long long ret = 0; 
        sort(horizontalCuts.begin(), horizontalCuts.end()); 
        sort(verticalCuts.begin(), verticalCuts.end()); 
        horizontalCuts.push_back(h); 
        verticalCuts.push_back(w); 
        int last = 0; 
        int max_h = 0; 
        for(int i = 0; i <= hc; i++) {
            max_h = max(max_h, horizontalCuts[i] - last); 
            last = horizontalCuts[i]; 
        }
        last = 0; 
        int max_w = 0; 
        for(int i = 0; i <= vc; i++) {
            max_w = max(max_w, verticalCuts[i] - last); 
            last = verticalCuts[i]; 
        }
        ret = (long long)max_w * (long long) max_h; 
        ret %= mod; 
        return ret; 
    }
};