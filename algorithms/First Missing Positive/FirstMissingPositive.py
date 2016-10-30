#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-10-30 14:03:55
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        for i in range(n):
        	while nums[i] > 0 and nums[i] <= n and nums[i] != i+1 :
        		if nums[i] == nums[nums[i]-1]:
        			break
        		nums[nums[i]-1], nums[i] = nums[i], nums[nums[i]-1]
        
        for i in range(n):
        	if i+1 != nums[i]: 
        		return i+1
        print nums
        return n+1

if __name__ == "__main__":
	x = Solution()
	print x.firstMissingPositive([3,4,-1,1])