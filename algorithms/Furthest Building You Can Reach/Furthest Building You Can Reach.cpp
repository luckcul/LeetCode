class Solution {
public:
    static bool cmp(int a, int b) {
        return a > b; 
    }
    bool check(vector<int> &diff, int m, int bricks, int ladders, vector<long long > &sums, vector<long long> &maxs) {
        if(ladders >= m+1) return true; 
        long long s = sums[m]-maxs[m]; 
        return s <= bricks; 
        /*vector<int> temp; 
        for(int i = 0; i <=m; i++) {
            temp.push_back(diff[i]); 
        }
        sort(temp.begin(), temp.end(), cmp); 
        int s = 0; 
        for(int i=ladders; i <= m; i++) {
             s += temp[i]; 
            if(s > bricks) return false; 
        }
        return true; 
        // return s <= bricks; 
        */
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        vector<int> diff; 
        diff.push_back(0); 
        for(int i = 1; i < heights.size(); i++) {
            int di = heights[i] - heights[i-1];
            diff.push_back(di>0 ? di:0); 
        }  
        int len = diff.size(); 
        
        vector<long long > sums; 
        for(int i = 0; i < len; i++) {
            if(i==0) sums.push_back(diff[i]); 
            else sums.push_back(diff[i] + sums[i-1]); 
        }
        priority_queue<int, vector<int>, greater<int> > q; 
        vector<long long > maxs; 
        long long te = 0; 
        for(int i = 0; i < len; i++) {
            q.push(diff[i]); 
            te += diff[i]; 
            if(i>=ladders) {
                long long ti = q.top(); 
                te -= ti; 
                q.pop(); 
            }
            maxs.push_back(te); 
        }
        
        int l = 0;
        int r = len-1; 
        int ret = 0; 
        while(l <= r) {
            int m = (l+r)/2; 
            bool f = check(diff, m, bricks, ladders, sums, maxs);  
            if(f) {
                l = m+1; 
                ret = m; 
            }
            else r = m-1; 
        }
        return ret; 
    }
};