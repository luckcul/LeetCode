#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-05-16 14:05:48
# @Author  : luckcul(tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        ret = 1123456789
        j = -1
        count = 0
        length = len(nums)
        for i in range(length):
            while count < s and j < length-1:
                j += 1
                count += nums[j]
            if count >= s:
                ret = min(ret, j - i + 1)
            count -= nums[i]
        return ret if ret != 1123456789 else 0


