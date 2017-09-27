class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> bits(words.size(), 0);
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words[i].size(); j++) {
                bits[i] |= (1<<(words[i][j] - 'a'));
            }
        }
        int ret = 0;
        for(int i = 0; i < bits.size(); i++) {
            for(int j = i+1; j < bits.size(); j++) {
                if(bits[i] & bits[j]) continue;
                ret = max(ret, (int)(words[i].size()) * (int)(words[j].size()));
            }
        }
        return ret;
    }
};