class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for(int i = 0; i < tasks.size(); i++) {
            cnt[tasks[i] - 'A'] ++;
        }
        sort(cnt.begin(), cnt.end());
        int s = 1;
        for(int i = 'Z' - 'A' - 1; i >= 0; i--) {
            if(cnt[i] == cnt[i+1]) s ++;
            else break;
        }
        return max(int(tasks.size()), (n + 1) * (cnt[25] - 1) + s);
    }
};
