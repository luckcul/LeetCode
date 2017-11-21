class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int leftMin = rectangles[0][0], botMin = rectangles[0][1], rightMax = rectangles[0][2], topMax = rectangles[0][3];
        int length = rectangles.size();
        set<pair<int, int>> S;
        int areas = 0; 
        for(int i = 0; i < length; i++) {
            int left = rectangles[i][0];
            int bot = rectangles[i][1];
            int right = rectangles[i][2];
            int top = rectangles[i][3];
            areas += (right - left) * (top - bot);
            leftMin = min(leftMin, left), botMin = min(botMin, bot); 
            rightMax = max(right, rightMax), topMax = max(topMax, top);
            pair<int, int> lb = make_pair(left, bot);
            pair<int, int> lt = make_pair(left, top);
            pair<int, int> rt = make_pair(right, top);
            pair<int, int> rb = make_pair(right, bot);
            if(S.find(lb) != S.end()) S.erase(lb);
            else S.insert(lb);
            if(S.find(lt) != S.end()) S.erase(lt);
            else S.insert(lt);
            if(S.find(rt) != S.end()) S.erase(rt);
            else S.insert(rt);
            if(S.find(rb) != S.end()) S.erase(rb);
            else S.insert(rb);
        }
        if(areas == (rightMax - leftMin) * (topMax - botMin) && S.size() == 4 && S.find(make_pair(leftMin, botMin)) != S.end()
    && S.find(make_pair(leftMin, topMax)) != S.end() && S.find(make_pair(rightMax, topMax)) != S.end() && S.find(make_pair(rightMax, botMin)) != S.end()){
        return true;
    }
        return false;
        
    }
};