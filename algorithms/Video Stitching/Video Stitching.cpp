class Solution {
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[0] < b[0]; 
    }
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        if(T == 0) return 0; 
        int ret = 1; 
        int len =clips.size(); 
        sort(clips.begin(), clips.end(), cmp); 
        // for(int i = 0; i < len; i++) cout<<clips[i][0]<<" "<<clips[i][1]<<" | "; 
        cout<<endl;
        int step = 0; 
        int next_step = 0; 
        for(int i = 0; i < len; i++) {
            if(clips[i][0] <= step) {
                next_step = max(next_step, clips[i][1]); 
                // cout<<"== "<<clips[i][1]<<endl;
            }
            else {
                if(clips[i][0] > next_step) return -1; 
                ret++; 
                step = next_step; 
                next_step = max(next_step, clips[i][1]);
            }
            // cout<<i<<" "<<ret<<" : "<<step<<" "<<next_step<<endl;
            if(next_step >= T) return ret; 
        }
        if(next_step < T) return -1; 
        return ret; 
    }
};