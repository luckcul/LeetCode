class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
		vector<vector<int> > ret;
		sort(nums.begin(), nums.end());
		int len = nums.size();
		for(int i = 0; i < len-3; i++) {
			if(i > 0 && nums[i] == nums[i-1]) continue;
			for(int j = i+1; j < len-2; j++) {
				if(j > i+1 && nums[j] == nums[j-1]) continue;
				int low = j+1, high = len-1;
				int w = target - nums[i] - nums[j];
				while(low < high) {
					int a = nums[low];
					int b = nums[high];
					if(a + b == w) {
						vector<int > v;
						v.push_back(nums[i]); v.push_back(nums[j]);
						v.push_back(a); v.push_back(b);
						ret.push_back(v);
						while(nums[low] == nums[low+1]) low++;
						while(nums[high] == nums[high-1]) high --;
						low++; high --;
					}
					else if(a+b > w) {
						while(nums[high] == nums[high-1]) high --; 
						high --;
					}
					else {
						while(nums[low] == nums[low+1]) low++;
						low++;
					}
				}
			}
		}
		return ret;        
    }
};