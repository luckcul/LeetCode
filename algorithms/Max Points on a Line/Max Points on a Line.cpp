/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 class Solution {
     int gcd(int a, int b) {
         if(a == 0) return b;
         return gcd(b%a, a);
     }
public:
    int maxPoints(vector<Point>& points) {
        int ret = 0;
        if(points.size() <= 2) return points.size();
        for(int i = 0; i < points.size(); i++) {
            int vertical = 0, horizontal = 0, localret = 0, over = 0;
            map<pair<int, int>, int> M;
            for(int j = i+1; j < points.size(); j++) {
                int dx = points[i].x - points[j].x;
                int dy = points[i].y - points[j].y;
                if(dx == 0 && dy == 0) {
                    over ++; continue;
                }
                if(dx == 0) {
                    vertical ++; continue;
                }
                if(dy == 0) {
                    horizontal ++; continue;
                }
                int g = gcd(dx, dy);
                int nx = dx / g, ny = dy / g;
                M[make_pair(nx, ny)] ++;
                localret = max(localret, M[make_pair(nx, ny)]);
            }
            localret = max(localret, max(vertical, horizontal));
            ret = max(ret, localret + over + 1);
        }
        return ret;
    }
};