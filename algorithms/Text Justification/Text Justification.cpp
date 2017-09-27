class Solution {
    string mergeString(vector<string> &words, int x, int y, int maxWidth, int xsize) {
        string ret = words[x];
        int leftSize = maxWidth - xsize + (y-x);
        int intervals = y - x;
        if(intervals == 0) {
            if(ret.size() < maxWidth) ret += string(maxWidth - ret.size(), ' ');
            return ret;
        }
        int ave = leftSize / intervals;
        int mod = leftSize % intervals;
        for(int i = 0; i < intervals; i++) {
            if(i < mod) {
                ret += string(ave+1, ' ');
            }
            else ret += string(ave, ' ');
            ret += words[x+i+1];
        }
        return ret;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        int lastSize = words[0].size(), lastIndex = 0;
        for(int i = 1; i < words.size(); i++) {
            int newSize = lastSize + 1 + words[i].size();
            if(newSize > maxWidth) {
                cout<<lastIndex<<endl;
                ret.push_back(mergeString(words, lastIndex, i-1, maxWidth, lastSize));
                lastIndex = i;
                lastSize = words[i].size();
            }
            else {
                lastSize = newSize;
            }
        }
        string lastS = words[lastIndex];
        for(int i = lastIndex + 1; i < words.size(); i++) lastS += " " + words[i];
        if(lastS.size() < maxWidth) lastS += string(maxWidth - lastS.size(), ' ');
        ret.push_back(lastS);
        return ret;
    }
};