#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-27 22:44:46
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        ret = []
        if len(nums) == 0 :
        	return ret
        l = nums[0]
        r = nums[0]
        for i in range(1, len(nums)):
        	if nums[i] == r + 1:
        		r = r+1
        	else:
        		if l == r:
        			ret.append(str(l))
        		else:
        			ret.append(str(l) + "->" + str(r))
        		l = r = nums[i]
        if l == r:
        	ret.append(str(l))
        else:
        	ret.append(str(l) + "->" + str(r))
        return ret 
print Solution().summaryRanges([0])        