#!/usr/bin/env pythonword2vec_basic.py
# -*- coding: utf-8 -*-
# @Time    : 17-10-24 下午1:25
# @Author  : luckcul
# @File    : Container With Most Water_On.py.py
# @version : 2.7
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        length = len(height)
        l,r = 0, length - 1
        ret = 0
        while l < r:
            min_ = min(height[l], height[r])
            ret = max(ret, min_ * (r - l))
            if min_ >= height[l]: l += 1
            if min_ >= height[r]: r -= 1
        return ret

