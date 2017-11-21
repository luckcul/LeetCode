class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int length = nums.size(); 
        if(length < 2) return 0; 
        int min_ = nums[0], max_ = nums[0]; 
        for(int i = 0; i < length; i++) min_ = min(min_, nums[i]), max_ = max(max_, nums[i]); 
        if(max_ - min_ < 1) return 0;  
        int bucket_size = (max_ - min_ - 1) / (length - 1) + 1;
        int bucket_num = (max_ - min_) / bucket_size + 1;
        vector<int> bucket_min(bucket_num), bucket_max(bucket_num), count(bucket_num, 0);
        for(int i = 0; i < length; i++) {
            int bucket_index = (nums[i] - min_) / bucket_size;
            if(count[bucket_index] == 0) {
                count[bucket_index]++;
                bucket_min[bucket_index] = nums[i];
                bucket_max[bucket_index] = nums[i];
                continue;
            }
            bucket_min[bucket_index] = min(bucket_min[bucket_index], nums[i]);
            bucket_max[bucket_index] = max(bucket_max[bucket_index], nums[i]);
        }
        int ret = bucket_size, last = bucket_max[0];
        for(int i = 1; i < bucket_num; i++) {
            if(count[i] < 1) continue;
            ret = max(ret, bucket_min[i] - last);
            last = bucket_max[i];
        }
        return ret;
    }
};