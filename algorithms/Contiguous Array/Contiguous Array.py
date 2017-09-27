#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 17-6-28 下午4:40
# @Author  : luckcul
# @File    : Contiguous Array.py
# @version : 2.7

class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        INF = 11234567
        Max = [-INF] * (2*length + 1)
        Min = [INF] * (2*length + 1)
        last = 0
        Max[length] = Min[length] = 0
        for i in range(length):
            if nums[i] == 1:
                last += 1
            else:
                last -= 1
            # print last
            Max[length + last] = max(Max[length + last], i+1)
            Min[length + last] = min(Min[length + last], i+1)
        ret = 0
        for i in range(length*2 + 1):
            if Max[i] == -INF:
                continue
            # print i, '--', Max[i], Min[i]
            ret = max(ret, abs(Max[i] - Min[i]))
        return ret
x = Solution()
print x.findMaxLength([0, 1])