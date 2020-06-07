class Solution {
    struct node {
        int val; 
        int abs_val; 
    }; 
public:
    static bool cmp(node & a, node & b) {
        if(a.abs_val == b.abs_val) return a.val > b.val; 
        return a.abs_val > b.abs_val; 
    }
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size(); 
        int m = (n-1)/2; 
        sort(arr.begin(), arr.end()); 
        int m_value = arr[m]; 
        cout<<m_value<<endl;
        vector<node> p; 
        for(int i = 0; i < n; i++) {
            node x; 
            x.val = arr[i]; 
            x.abs_val = abs(arr[i]-m_value); 
            p.push_back(x); 
        }
        sort(p.begin(), p.end(), cmp); 
        vector<int> ret; 
        for(int i = 0; i < k; i++) {
            ret.push_back(p[i].val); 
        }
        return ret; 
    }
};