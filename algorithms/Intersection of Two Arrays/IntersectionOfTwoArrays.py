#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-25 21:31:31
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        x = set(nums1)
        y = set(nums2)
        return list(x&y)

print Solution().intersection([1,2,2,1], [2,2,3])