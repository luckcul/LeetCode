class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.size() < 1) return true;
        vector<int> v;
        for(int i = 0; i < preorder.size(); i++) {
            if(preorder[i] == ',') {
                v.push_back(preorder[i-1] == '#' ? 0:1);
            }
        }
        v.push_back(preorder.back() == '#' ? 0:1);
        int diff = 1;
        for(int i = 0; i < v.size(); i++) {
            diff --; 
            if(diff < 0) return false;
            if(v[i]) diff += 2;
        }
        return diff == 0;
    }
};