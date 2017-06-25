#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-05-21 14:53:29
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        using XOR, O(n)
        """
        n = len(nums)
        ret = 0
        for i in range(n):
            ret ^= i
            ret ^= nums[i]
        return ret ^ n
