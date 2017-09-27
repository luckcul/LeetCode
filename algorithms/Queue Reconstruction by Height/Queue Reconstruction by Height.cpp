class Solution {
    static int cmp(pair<int, int> x, pair<int, int> y){
        // if(x.second == y.second) return x.first 
        return x.second < y.second;
    }
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> ret;
        sort(people.begin(), people.end(), cmp);
        for(int i = 0; i < people.size(); i++) {
            pair<int, int> tempP = people[i];
            int index = 0, count = 0; 
            while(index < ret.size()) {
                if(tempP.first <= ret[index].first) count ++;
                if(count > tempP.second) break;
                index ++;
            }
                ret.insert(ret.begin()+index, tempP);
        }
        return ret;
    }
};