class Solution {
public:
    int hIndex(vector<int>& citations) {
        // reverse(citations.begin(), citations.end());
        int ret = 0, length = citations.size();
        int l = 0, r = length-1;
        while(l <= r) {
            int m = (l+r)>>1;
            if(citations[m] >= length - m){
                ret = length - m; r = m - 1;
            }
            else l = m + 1;
        }
        return ret;
    }
};
