class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        list<int> li(arr.begin(), arr.end()); 
        int len = arr.size(); 
        if(k > len) k = len; 
        int last = -1; 
        int con = 0; 
        
        while(true) {
            list<int>::iterator sec = li.begin(); 
            sec++; 
            list<int>::iterator fir = li.begin(); 
            if(*fir > *sec) {
                con++; 
            }
            else {
                int tmp = *fir; 
                *fir = *sec;
                *sec = tmp; 
                con = 1; 
            }
            int tmp = *sec;
                li.erase(sec); 
                li.push_back(tmp); 
            last = *fir;
            if(con >= k) {
                break;
            }
        }
        return last; 
    }
};