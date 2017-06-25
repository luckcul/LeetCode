class Solution {
public:
    bool isPalindrome(int x) {
    	if(x < 0) return false;
        int originX = x;
        int lenght = 0;
        while(x) {
        	lenght ++;
        	x /= 10;
        }
        // cout<<lenght<<endl;
        x = originX;
        for(int i = 0; i < lenght/2; i++) {
        	int left = x %10;
        	x /= 10;
        	// cout<<(int(pow(10, lenght-i-1) + 0.1)) <<endl;
        	int right = (originX / (int(pow(10, lenght-i-1) + 0.1)) )%10;
        	// cout<<right<<endl;
        	if(left != right) return  false;
        }
        return true;
    }
};
