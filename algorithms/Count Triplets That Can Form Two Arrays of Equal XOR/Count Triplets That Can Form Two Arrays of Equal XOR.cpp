class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int len = arr.size(); 
        vector<int> bits; 
        bits.push_back(0); 
        for(int i = 0; i < len; i++) {
            bits.push_back(bits[i] ^ arr[i]); 
        }
        cout<<"ok"<<endl;
        int ret = 0; 
        for(int i = 0; i < len; i++) {
            for(int j = i+1; j < len; j++) {
                for(int k = j; k < len; k++) {
                    int a = bits[j] ^ bits[i]; 
                    int b = bits[k+1] ^ bits[j]; 
                    // cout<<i<<", "<<j<<", "<<k<<": "<<a<<", "<<b<<endl;
                    if(a == b) ret ++; 
                }
            }
        }
        return ret; 
    }
};