class MedianFinder {
    vector<int> nums;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        nums.clear();
    }
    
    void addNum(int num) {
        vector<int>::iterator it =lower_bound(nums.begin(), nums.end(), num);
        nums.insert(it, num);
    }
    
    double findMedian() {
        if(nums.size() & 1) {
            return nums[nums.size()/2];
        }
        else return (nums[nums.size()/2 -1] + nums[nums.size()/2]) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */




class MedianFinder {
    priority_queue<int> small, large;
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if(small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if(small.size() == large.size()) return (small.top() - large.top()) / 2.0;
        return small.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */