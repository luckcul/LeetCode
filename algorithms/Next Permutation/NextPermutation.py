#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-02-16 09:41:03
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12


class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        L = len(nums)
        index = -1
        for i in range(L-1, 0, -1):
            if nums[i] > nums[i-1]:
                index = i-1
                break
        l, r = 0, 0
        if index == -1:
            l = 0
            r = L-1
        else :
            l = index+1
            r = L-1
            swapValue = nums[l]
            swapIndex = l 
            for i in range(l, r+1):
                if nums[i] > nums[index] and swapValue > nums[i]:
                    swapValue = nums[i]
                    swapIndex = i
            nums[index], nums[swapIndex] = nums[swapIndex], nums[index]
        for t in range(r-l):
            for i in range(l, r):
                if nums[i] > nums[i+1]:
                    nums[i], nums[i+1] = nums[i+1], nums[i]

x = Solution()
t = [5, 1, 3, 4, 2]            
x.nextPermutation(t)
print t