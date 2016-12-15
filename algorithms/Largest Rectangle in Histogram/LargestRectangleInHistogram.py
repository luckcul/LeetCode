#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-12-05 22:31:54
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        length = len(heights)
        l = [0]*(length+2)
        r = [0]*(length+2)
        x = [-1]
        x.extend(heights)
        x.append(-1)
        for i in range(1,length + 1):
        	j = i-1
        	while x[j] >= x[i]:
        		j = l[j]
        	l[i] = j
        for i in range(length, 0, -1):
        	j = i+1
        	while x[j] >= x[i]:
        		j = r[j]
        	r[i] = j
        ret = 0
        for i in range(1, length+1):
        	ret = max(ret, x[i]*(r[i]-l[i]-1))
        return ret

print Solution().largestRectangleArea([2,1,5,6,2,3])        