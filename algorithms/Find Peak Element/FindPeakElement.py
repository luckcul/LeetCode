#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-02 16:05:00
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        negINF = -91234567890
        length = len(nums)
        nums = [negINF] + nums + [negINF]
        l = 1
        r = length
        while l <= r:
        	m = (l+r)/2
        	if nums[m] > nums[m-1] and nums[m] > nums[m+1]:
        		break
        	elif nums[m+1] > nums[m]:
        		l = m+1
        	else:
        		r = m-1
        return m-1

if __name__ == "__main__":
	x = Solution()
	print x.findPeakElement([1, -1])        