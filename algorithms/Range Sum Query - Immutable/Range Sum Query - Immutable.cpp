class NumArray {
    private:
    vector<int> s; 
public:
    NumArray(vector<int> nums) {
        int si = 0; 
        s.push_back(0);
        for(int i = 0; i < nums.size(); i++) {
            si += nums[i];
            s.push_back(si); 
        }
    }
    
    int sumRange(int i, int j) {
        return s[j+1] - s[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */