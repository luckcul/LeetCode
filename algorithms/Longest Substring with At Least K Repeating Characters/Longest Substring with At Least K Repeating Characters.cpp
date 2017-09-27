class Solution {
public:
    int longestSubstring(string s, int k) {
        int ret = 0;
        for(int i = 0; i + k <= s.size(); ) {
            vector<int> cnt(27, 0);
            int mask = 0, index_max = -1;
            for(int j = i; j < s.size(); j++) {
                int dig = s[j] - 'a';
                cnt[dig] ++;
                if(cnt[dig] < k) {
                    mask |= (1<<dig);
                }
                else {
                    mask &= (~(1<<dig));
                }
                if(mask == 0) {
                    ret = max(ret, j - i + 1);
                    index_max = j;
                }
            }
            if(index_max == -1) i++;
            else i = index_max + 1;
        }
        return ret;
    }
};