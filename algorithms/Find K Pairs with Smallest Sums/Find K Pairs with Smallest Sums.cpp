class Solution {
    struct node {
        int index1, index2, sum;
        node(int id1, int id2, int s):index1(id1), index2(id2), sum(s){}
        friend bool operator<(node x, node y) {
            return x.sum > y.sum;
        }
    };
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> ret; 
        int k1 = min(k, int(nums1.size()));
        int k2 = min(k, int(nums2.size()));
        if(!k1 || !k2) return ret;
        priority_queue<node> Q;
        for(int i = 0; i < k1; i++) {
            Q.push(node(i, 0, nums1[i] + nums2[0]));
        }
        while(!Q.empty()) {
            node now = Q.top();
            Q.pop();
            ret.push_back(make_pair(nums1[now.index1], nums2[now.index2]));
            if(ret.size() >= k) break;
            if(now.index2 + 1 < k2) {
                Q.push(node(now.index1, now.index2+1, nums1[now.index1] + nums2[now.index2+1]));
            }
        }
        return ret;
    }
};