class Solution {
public: 
    int longestSubarray(vector<int>& nums, int limit) {
        int len = nums.size();  
        int ret = 0; 
        int i = 0; 
        int j = 0; 
        multiset<int> M; 
        M.insert(nums[0]); 
        while(i < len) {
            // cout<<nums[i]<<endl;
            while(j < len) {
                
                multiset<int>::iterator it_max = M.end(); 
                it_max --;
                multiset<int>::iterator it_min = M.begin(); 
                if(*it_max - *it_min <= limit) {
                    ret = max(ret, j-i+1); 
                    j++; 
                    if(j < len) M.insert(nums[j]); 
                }
                else {
                    break; 
                }
            }
            multiset<int>::iterator it = M.find(nums[i]); 
            // for(multiset<int>::iterator it = M.begin(); it!=M.end(); it++) {
            //     cout<<*it<<", ";
            // }
            cout<<endl;
            M.erase(it); 
            i++; 
        }
        return ret; 
    }
};