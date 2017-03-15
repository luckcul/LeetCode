class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
			
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i = 0; i < size; i++) {
        	if(i > 0 && nums[i] == nums[i-1]) continue;//make sure unique triplets
        	int low = i+1, high = size-1;
        	while(low < high) {
        		if(nums[i] + nums[low] + nums[high] == 0) {
        			vector<int> temp; 
        			temp.push_back(nums[i]); 
        			temp.push_back(nums[low]); 
        			temp.push_back(nums[high]);
        			ret.push_back(temp);
        			low++; high--;
                    // following make sure unique triplets
        			while(nums[low] == nums[low-1]) low ++; 
        			while(nums[high] == nums[high+1]) high --;
        		}
        		else if(nums[i] + nums[low] + nums[high] > 0) {
        			high--;
        			while(nums[high] == nums[high+1]) high --;
        		}
        		else{
        			low++;
        			while(nums[low] == nums[low-1]) low ++;
        		} 
        	}
        }
        return ret;
    }
};
