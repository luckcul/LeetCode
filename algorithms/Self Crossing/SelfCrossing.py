#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-29 09:31:51
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def isSelfCrossing(self, x):
        """
        :type x: List[int]
        :rtype: bool
        """
        length = len(x)
        t = length / 4
        t = t + 1 if length%4 != 0 else t
        for i in range(t):
        	s = i*4
        	up = min(s+4, length)
        	for j in range(s, up):
        		if j-3 >= 0 and x[j] >= x[j-2] and x[j-3] >= x[j-1] :
        			return True
        		if j-4 >= 0 and x[j] + x[j-4] >= x[j-2] and x[j-3] == x[j-1]:
        			return True
        		if j-5 >= 0 and x[j-5] + x[j-1] >= x[j-3] and x[j-4] + x[j] >= x[j-2] and x[j-2] >= x[j-4] and x[j-3] >= x[j-1]:
        			return True
        return False
print Solution().isSelfCrossing([1,1,2,2,3,3,4,4,10,4,4,3,3,2,2,1,1])