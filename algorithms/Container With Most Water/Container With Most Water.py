#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 17-10-24 下午1:10
# @Author  : luckcul
# @File    : Container With Most Water.py
# @version : 2.7
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        l = [[i, ele] for i, ele in enumerate(height)]
        l.sort(key=lambda x:x[1], reverse=True)
        max_ = -10**10
        min_ = 10**10
        ret = 0
        for i, ele in l:
            max_ = max(max_, i)
            min_ = min(min_, i)
            ret = max(ret, (max_ - min_) * ele)
        return ret

