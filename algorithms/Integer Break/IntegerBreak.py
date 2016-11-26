#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-26 20:14:27
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        ret = 0
        for i in range(2, n+1):
        	ave = n / i
        	ave1 = ave + 1
        	s = ave * i 
        	sl = n - s 
        	cou2 = sl
        	cou1 = i - cou2
        	ans = int(pow(ave, cou1) * pow(ave1, cou2))
        	if ans > ret:
        		ret = ans
        	else :
        		break 
        return ret