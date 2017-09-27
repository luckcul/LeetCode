class Solution {
    int calDis(vector<int> &p1, vector<int> &p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
    bool check(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4){
        vector<int> dis1;
        dis1.push_back(calDis(p1, p2));
        dis1.push_back(calDis(p1, p3));
        dis1.push_back(calDis(p1, p4));
        sort(dis1.begin(), dis1.end());
        if(dis1[0] == 0 || dis1[0] != dis1[1] || dis1[0] * 2 != dis1[2]) return false;
        return true;
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(check(p1, p2, p3, p4) && check(p2, p1, p3, p4) && check(p3, p1, p2, p4) && check(p4, p1, p2, p3))
            return true;
        return false;
    }
};