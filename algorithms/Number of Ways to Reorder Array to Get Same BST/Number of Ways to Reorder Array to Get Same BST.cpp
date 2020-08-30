class Solution {
    long long c[1123][1123]; 
    long long mod=1000000007; 
    struct node {
        int value; 
        node * left; 
        node * right; 
        node(int x) : value(x), left(NULL), right(NULL) {}
    }; 
    struct Res {
        long long cnt; 
        int node_cnt; 
    }; 
public:
    Res dfs(node * root) {
        Res res; 
        
        if(!root) {
            res.cnt = 1; 
            res.node_cnt = 0; 
             return res; 
        }
        Res res_left = dfs(root->left); 
        Res res_right = dfs(root->right); 
        res.node_cnt = res_left.node_cnt + res_right.node_cnt+1; 
        long long cnt = c[res.node_cnt-1][res_left.node_cnt]; 
        // cout<<"zuhe cnt "<<res.node_cnt<<", "<<res_left.node_cnt<<", "<<cnt<<endl; 
        cnt *= res_left.cnt; 
        cnt %= mod; 
        cnt *= res_right.cnt; 
        cnt %= mod; 
        res.cnt = cnt; 
        // cout<<"root value "<<root->value<<", "<<(res.node_cnt)<<", "<<(res.cnt)<<endl;
        return res; 
    }
    void insert(node * root, int value) {
        int root_val = root->value; 
        if(root_val > value) {
            if(!(root->left) ) {
                root->left = new node(value); 
            } 
            else {
                insert(root->left, value); 
            }
        } 
        else {
            if(!(root->right)) {
                root->right = new node(value); 
            }
            else {
                insert(root->right, value); 
            }
        }
    }
    int numOfWays(vector<int>& nums) {
        for(int i = 0; i <= 1000; i++) {
            for(int j = 0;  j <= i; j++) {
                if(j == 0 || j == i) {
                    c[i][j] = 1; 
                }
                else {
                    c[i][j] = c[i-1][j-1] + c[i-1][j]; 
                }
                c[i][j] %= mod; 
            }
        }
        // cout<<" c ok "<<c[2][1]<<endl;
        node *root = new node(nums[0]); 
        for(int i = 1; i < nums.size(); i++) {
            insert(root, nums[i]); 
        }
        // cout<<"insert ok"<<endl;
        Res ret = dfs(root); 
        return (ret.cnt-1+mod) % mod; 
    }
};