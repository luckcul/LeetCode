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
        int index = 0;
        return dfs(v, index) && index == v.size()-1;
    }
    bool dfs(vector<int> &preorder, int &index) {
        if(index >= preorder.size()) return false;
        if(preorder[index]) {
            index++;
            bool flag1 = dfs(preorder, index);
            index++;
            bool flag2 = dfs(preorder, index);
            return flag1 && flag2;
        }
        
        return true;
    }
};