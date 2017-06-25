class Solution {
	int reverseP(int x) {
		int max = (1<<31) -1;
		// cout<<max<<endl;
		int ret = 0;
        while(x) {
        	if(ret > max/10) return 0;
        	ret *= 10;
        	if(ret > max - x%10) return 0;
        	ret += x % 10;
        	x /= 10;
        }
        return ret;
	}
public:
    int reverse(int x) {
    	if(x == (1<<31)) return 0;
    	int neg = 1;
    	if(x < 0) neg = -1, x = -x;
        int ret = reverseP(x);

        return ret * neg;
    }
};