class NumArray {
    vector<int> nums, ori; 
public:
    NumArray(vector<int> nums) {
        this->nums = vector<int>(nums.size(), 0);
        this->ori = vector<int>(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
            update(i, nums[i]);
        }
    }
    int lowbit(int x) {
        return x & (-x);
    }
    void update(int i, int val) {
        int diff = val - ori[i];
        // cout<<diff<<endl;
        ori[i] = val;
        i++;
        while(i <= nums.size()) {
            nums[i-1] += diff;
            i += lowbit(i);
        }
    }
    int getSum(int x) {
        int ret = 0; 
        while(x > 0) {
            ret += nums[x - 1];
            x -= lowbit(x);
        }
        return ret;
    }
    int sumRange(int i, int j) {
        // cout<<getSum(j+1)<<" "<<getSum(i)<<endl;
        // for(int i = 0; i < nums.size(); i++) cout<<nums[i]<<endl;
        return getSum(j+1) - getSum(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */