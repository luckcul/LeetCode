/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    stack<vector<NestedInteger>::iterator> begins, ends;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next() {
        auto top_b = begins.top();
        int ret = top_b->getInteger();
        begins.top() ++;
        return ret;
    }

    bool hasNext() {
        while(true) {
            if(begins.empty()) return false;
            auto top_b = begins.top();
            auto top_e = ends.top();
            if(top_b == top_e) {
                begins.pop(); ends.pop();
                continue;
            }
            if(top_b->isInteger()) return true;
            begins.top() ++;
            begins.push(top_b->getList().begin());
            ends.push(top_b->getList().end());
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */