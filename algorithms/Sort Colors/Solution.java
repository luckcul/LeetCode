public class Solution {
    public void sortColors(int[] nums) {
        int[] count = new int[3];
        int zeros, ones, twos;
        zeros = ones = twos = 0;
        for(int i = 0; i < nums.length; i++) {
        	count[nums[i]] += 1;
        }
        int last = 0, sum = 0;
        for(int i = 0; i < 3; i++) {
        	sum += count[i];
        	for(; last < sum; last++ ){
        		nums[last] = i;
        	}
        }
    }
    // public static void main(String args[]) {
    //     Solution x = new Solution();
    //     int[] nums = {0, 1, 2, 0, 0, 2, 2};
    //     x.sortColors(nums);
    //     for(int i = 0; i < nums.length; i++) System.out.println(nums[i]);
    // }
}