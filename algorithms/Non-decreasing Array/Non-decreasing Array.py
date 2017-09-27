#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 17-8-31 下午1:17
# @Author  : luckcul
# @File    : Non-decreasing Array.py
# @version : 2.7
class Solution(object):
    def checkPossibility(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        count = 0
        length = len(nums)
        if length <= 1:
            return True
        for i in range(1, length):
            if nums[i] <nums[i-1]:
                count += 1
                if i-2 < 0 or nums[i-2] <= nums[i] :
                    nums[i-1] = nums[i-2]
                else:
                    nums[i] = nums[i-1]
        return count <= 1
