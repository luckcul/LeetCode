class Solution {
public:
    vector<int> getRow(int rowIndex) {
        //c(n, m) = n! / (m! * (n-m)!)
        vector<int> ret;
        ret.push_back(1);
        for(int i = 1; i <= rowIndex; i++) {
            ret.push_back((long long)ret[i-1] * (rowIndex -i+1) / i);
        }
        return ret;
    }
};