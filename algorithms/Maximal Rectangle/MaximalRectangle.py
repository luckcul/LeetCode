#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-12-06 12:23:55
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        ret = 0
        n = len(matrix)
        m = 0 if n == 0 else len(matrix[0])
        print n, m
        num = [0]*(m+2)
        num[0] = num[m+1] = -1
        for i in range(0, n):
        	for j in range(0, m):
        		num[j+1] = 0 if matrix[i][j] == '0' else num[j+1] + 1
        	l = [0]*(m+2)
        	r = [0]*(m+2)
        	for i1 in range(1, m+1):
        		j = i1-1
        		while num[i1] <= num[j] :
        			j = l[j]
        		l[i1] = j
        	for i1 in range(m, 0, -1):
        		j = i1+1
        		while num[i1] <= num[j] :
        			j = r[j]
        		r[i1] = j
        	ans = 0
        	for i1 in range(1, m+1):
        		ans = max(ans, num[i1] * (r[i1] - l[i1] -1))
        	ret = max(ans, ret)
        return ret 
# print Solution().maximalRectangle([[1,0,1,0,0],[1,0,1,1,1],[1,1,1,1,1],[1,0,0,1,0]])
print Solution().maximalRectangle(["10100","10111","11111","10010"])