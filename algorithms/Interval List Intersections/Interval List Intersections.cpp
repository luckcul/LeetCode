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
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        int len_a = A.size(); 
        int len_b = B.size(); 
        vector<Interval> ret; 
        int idx1 = 0, idx2 = 0; 
        while(idx1 < len_a && idx2 < len_b) {
            if(A[idx1].end < B[idx2].start) {
                idx1++; 
                continue;
            }
            if(B[idx2].end < A[idx1].start) {
                idx2 ++; 
                continue;
            }
            int s = max(A[idx1].start, B[idx2].start); 
            int e = min(A[idx1].end, B[idx2].end); 
            ret.push_back(Interval(s, e)); 
            if(A[idx1].end == e) idx1++; 
            if(B[idx2].end == e) idx2++; 
            
        }
        return ret; 
        
    }
};