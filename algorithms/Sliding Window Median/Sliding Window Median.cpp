class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> small; 
        priority_queue<int,vector<int>, greater<int>> large;
        unordered_map<int, int> hash; 
        for(int i = 0; i < k; i++) small.push(nums[i]);
        for(int i = 0; i < k/2; i++) large.push(small.top()), small.pop();
        vector<double> ret;
        for(int i = k; ; i++) {
            if(!(k&1)) nowValue = (nowValue + large.top())/2;
            ret.push_back(nowValue); 
            if(i >= nums.size()) break;
            int balance = 0; 
            // remove
            if(nums[i-k] <= small.top()) balance--;
            else balance++;
            hash[nums[i-k]] ++;

            if(nums[i] <= small.top()) {
                balance ++; small.push(nums[i]);
            }
            else {
                balance --; large.push(nums[i]);
            }
            while(balance > 0 || (!small.empty() && hash[small.top()])) {
                if(!small.empty() && hash[small.top()]) {
                    hash[small.top()] --; 
                    small.pop();
                }
                else {
                    balance -= 2; 
                    large.push(small.top());
                    small.pop();
                }
            }
            while(balance < 0 || (!large.empty() && hash[large.top()])) {
                if(!large.empty() && hash[large.top()]) {
                    hash[large.top()] --; 
                    large.pop();
                }
                else {
                    balance += 2; 
                    small.push(large.top());
                    large.pop();
                }
            }
        }
        return ret;
    }
};