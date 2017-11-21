class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        int length = positions.size(); 
        vector<int> height(length, 0);
        vector<int> ret; 
        int lastMax = 0;
        for(int i = 0; i < length; i++) {
            int leftI = positions[i].first;
            int rightI = positions[i].second + leftI - 1;
            int height_s = 0; 
            for(int j = 0; j < i; j++) {
                int leftJ = positions[j].first;
                int rightJ = positions[j].second + leftJ - 1;
                if(!(leftJ > rightI || leftI > rightJ)) {
                    height_s = max(height_s, height[j]);
                }
            }
            int height_e = height_s + positions[i].second;
            lastMax = max(lastMax, height_e);
            ret.push_back(lastMax);
            height[i] = height_e;
        }
        return ret;
    }
};