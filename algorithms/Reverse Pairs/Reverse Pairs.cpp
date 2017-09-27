
// implement BIT
class Solution {
    int lowbit(int x) {
        return x & (-x);
    }
    int getSum(vector<int> &c, int x) {
        int ret = 0; 
        while(x > 0) {
            ret += c[x];
            x -= lowbit(x);
        }
        return ret;
    }
    void insert(vector<int> &c, int x) {
        while(x < c.size()) {
            c[x] += 1;
            x += lowbit(x);
        }
    }
public:
    int reversePairs(vector<int>& nums) { // size : 50,000
        vector<int> bit(nums.size()+1, 0);
        long long ret = 0; 
        vector<int> cp(nums);
        sort(cp.begin(), cp.end());
        for(int i = 0; i < nums.size(); i++) {
            // cout<<i<<endl;
            int index = getIndex(cp, (long long)nums[i] * 2 + 1);
            if(index != 0){
                int tempS = i - getSum(bit, index - 1);
                ret += tempS;
            }
            insert(bit, getIndex(cp, nums[i]));
        }
        return ret;
    }
    int getIndex(vector<int> &nums, long long val) {
        int l = 0, r = nums.size() - 1, ret = -1;
        while(l <= r) {
            int m = (l + r)>>1;
            if(nums[m] >= val) {
                r = m - 1; ret = m;
            }
            else {
                l = m + 1;
            }
        }
        return ret + 1;
    }
};

// implement BST ( not balance,  so i got TLE)
class Solution {
    struct node {
        int val,cnt;
        struct node *left, *right;
        node(int x):val(x),cnt(1),left(NULL),right(NULL){}
    };
    node *insert(node *root, int val) {
        if(root == NULL) {
            return new node(val);
        }
        if(val == root->val) {
            root->cnt ++;
        }
        else if(val > root->val) {
            root->cnt ++;
            root->right = insert(root->right, val);
        }
        else {
            root->left = insert(root->left, val);
        }
        return root;
    }
    int search(node *root, long long val) {
        if(root == NULL) return 0;
        if(root->val == val) {
            return root->cnt;
        }
        else if(root->val > val) {
            return root->cnt + search(root->left, val);
        }
        else {
            return search(root->right, val);
        }
    }
public:
    int reversePairs(vector<int>& nums) { // size : 50,000
        node *root = NULL;
        int ret = 0;
        for(int i = 0; i < nums.size(); i++) {
            ret += search(root, (long long)(nums[i]) * 2 +1);
            root = insert(root, nums[i]);
        }
        return ret;
    }
};

// Trie , but this solution can not deal with negtive nums, so i got wa
class Solution {
    struct node {
        int val;
        struct node *left, *right;
        node(int x):val(x),left(NULL),right(NULL){}
    };
    void insert(node *root, int depth, int num) {
        root->val ++;
        if(depth == -1) return ;
        int bit = num & (1<<depth);
        if(bit){
            if(root->right == NULL) root->right = new node(0);
            insert(root->right, depth - 1, num);
        }
        else {
            if(root->left == NULL) root->left = new node(0);
            insert(root->left, depth -1 , num);
        }
    }
    int count(node *root, int depth, int num) {// find < num
        int bit = num & (1<<depth);
        int ret = 0;
        if(bit) {
            ret += (root->left ? root->left->val : 0);
            if(root->right) ret += count(root->right, depth - 1, num);
        }
        else{
            if(root->left) ret += count(root->left, depth - 1, num);
        }
        return ret;
    }
public:
    int reversePairs(vector<int>& nums) { // size : 50,000
        node *root = new node(0);
        int ret = 0;
        for(int i = nums.size() - 1; i >= 0; i--) {
            ret += count(root, 31, nums[i]);
            insert(root, 31, nums[i]*2);
        }
        return ret;
    }
};
