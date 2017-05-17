
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    	vector<vector<int>> ret = {{}};
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ) {
        	int count = 0;
        	while(i + count < nums.size() && nums[i + count] == nums[i]) count ++;
        	int lastTotal = ret.size();
        	for(int j = 0; j < lastTotal; j ++) {
        		vector<int> temp = ret[j];
        		for(int k = 0; k < count; k ++) {
        			temp.push_back(nums[i]);
        			ret.push_back(temp);
        		}
        	}
        	i += count;
        }
        return ret;
    }
};
