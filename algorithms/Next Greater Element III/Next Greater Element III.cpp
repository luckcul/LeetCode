class Solution {
    vector<int> getSingle(int n) {
        vector<int> ret;
        while(n) {
            ret.push_back(n%10);
            n /= 10;
        }
        return ret;
    }
    int generateInt(vector<int> &dig) {
        int ret = 0, upper = (1<<31)-1;
        for(int i = dig.size() - 1; i >= 0; i--) {
            if(ret > upper/10 || (ret == upper/10 && dig[i] > 7)) return -1;
            ret *= 10; 
            ret += dig[i];
        }
        return ret;
    }
public:
    int nextGreaterElement(int n) {
        vector<int> dig = getSingle(n);
        int index = -1;
        for(int i = 1; i < dig.size(); i++) {
            if(dig[i] < dig[i-1]){
                index = i; break;
            }
        }
        if(index == -1) return -1;
        int upBoundIndex = index-1, upBound = dig[index-1];
        for(int i = 0; i < index; i++) {
            if(dig[i] > dig[index] && upBound > dig[i]) {
                upBoundIndex = i; upBound = dig[i];
            } 
        }
        // cout<<index<<" "<<upBoundIndex<<endl;
        swap(dig[index], dig[upBoundIndex]);
        sort(dig.begin(), dig.begin()+index);
        reverse(dig.begin(), dig.begin() + index);
        int ret = generateInt(dig);
        return ret;
    }
};