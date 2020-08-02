class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(); 
        int len2 = nums2.size(); 
        vector<int> same_v, same_idx1, same_idx2; 
        int idx1=0, idx2=0; 
        while(idx1 < len1 && idx2 < len2) {
            if(nums1[idx1] == nums2[idx2]) {
                same_v.push_back(nums1[idx1]); 
                same_idx1.push_back(idx1); 
                same_idx2.push_back(idx2); 
                idx1++; idx2++; 
            }
            else if(nums1[idx1] > nums2[idx2]) {
                idx2++; 
            }
            else idx1++; 
        }
        int n = same_v.size(); 
        vector<long long> s1, s2; 
        for(int i = 0; i <= n; i++) {
            int start1 = (i == 0 ? 0:same_idx1[i-1]+1); 
            int start2 = (i == 0 ? 0:same_idx2[i-1]+1); 
            int end1 = (i == n ? len1:same_idx1[i]); 
            int end2 = (i == n ? len2:same_idx2[i]); 
            
            long long si1 = 0; 
            for(int j = start1; j < end1; j++) {
                si1 += nums1[j]; 
            }
            long long si2 = 0; 
            for(int j = start2; j < end2; j++) {
                si2 += nums2[j]; 
            }
            s1.push_back(si1); 
            s2.push_back(si2); 
            // if(i<n)
            // cout<<same_v[i]<<", "<<same_idx1[i]<<", "<<same_idx2[i]<<": "<<si1<<", "<<si2<<endl;
        }
        vector<vector<long long> > dp(n+1, vector<long long>(2, 0L)); 
        for(int i = 0; i < n; i++) {
            dp[i+1][0] = dp[i][0] + s1[i] + same_v[i]; 
            dp[i+1][0] = max(dp[i+1][0], dp[i][1] + s2[i] + same_v[i]); 
            dp[i+1][1] = dp[i][1] + s2[i] + same_v[i]; 
            dp[i+1][1] = max(dp[i+1][1], dp[i][0] + s1[i] + same_v[i]); 
        }
        long long mod = 1e9+7;
        return max(dp[n][0] + s1[n], dp[n][1] + s2[n]) % (mod);
    }
};