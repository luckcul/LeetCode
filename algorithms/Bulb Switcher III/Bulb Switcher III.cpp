class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int size = light.size(); 
        int ret = 0; 
        int max_v = 0; 
        for(int i = 0; i < size; i++) {
            max_v = max(max_v, light[i]); 
            if(max_v == i+1) {
                ret ++; 
            }
        }
        return ret; 
        
        /*
        
        vector<int> vis(size+1, 1123456); 
        for(int i = 0; i < size; i++) {
            int num = light[i]; 
            vis[num-1] = i; 
        }
        int ret = 1; 
        int max_v = vis[0]; 
        for(int i = 1; i < size; i++) {
            if(vis[i] > max_v) {
                ret ++; 
            }
            max_v = min(max_v, vis[i]); 
        }
        return ret; 
        */
    }
};