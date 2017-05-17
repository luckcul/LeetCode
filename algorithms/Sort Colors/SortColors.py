#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-04-14 16:30:00
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        L = len(nums)
        low, cur , high = 0, 0, L - 1
        while cur <= high :
        	if nums[cur] == 1:
        		cur += 1
        	elif nums[cur] < 1:
        		nums[low], nums[cur] = nums[cur], nums[low]
        		low += 1
        		cur += 1
        	else :
        		nums[cur], nums[high] = nums[high], nums[cur]
        		high -= 1

