/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    static bool cmp(Interval x, Interval y) {
        return x.start < y.start;
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() == 0) return intervals;
        sort(intervals.begin(), intervals.end(), cmp); 
        int j = 0; 
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i].start <= intervals[j].end) {
                intervals[j].end = max(intervals[j].end, intervals[i].end);
            }
            else {
                intervals[++j] = intervals[i];
            }
        }
        vector<Interval> ret(intervals.begin(), intervals.begin() + j + 1);
        return ret;
    }
};