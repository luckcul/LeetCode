class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	sort(nums.begin(), nums.end());
    	vector<int> ret; 
    	int low = 0, high = nums.size() - 1; 
    	while(low < high){
    		int sum = nums[low] + nums[high] ; 
    		if(sum == target) {
    			ret.push_back(low); 
    			ret.push_back(high); 
    		}
    		else if(sum > target) {
    			high --; 
    		}
    		else {
    			low --; 
    		}
    	}
    	return ret; 
    }
};