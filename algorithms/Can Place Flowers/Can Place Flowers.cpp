class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int last = 0, sum = 0;
        for(int i = 0; i < flowerbed.size(); i++) {
            if(flowerbed[i] == 1) {
                last = 1; 
            }
            else {
                if(last == 1) {
                    last = 0;
                }
                else {
                    if((i+1 < flowerbed.size() && flowerbed[i+1] != 1) || i+1 >= flowerbed.size()) {
                        sum ++;
                        last = 1;                        
                    }
                    else last = 0;
                }
            }
            if(sum >= n) return true;
        }
        return false;
    }
};