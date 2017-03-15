#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-02-22 21:40:17
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
   
    def combinationSum4(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        dp = [0] * (target+1)
        dp[0] = 1
        for i in range(1, target+1) :
        	for num in nums:
        # for num in nums:
        	# for i in range(1, target +1):
        		if i - num >= 0: dp[i] += dp[i-num]
        return dp[target]

x = Solution()
print (x.combinationSum4([1, 2, 3], 4))