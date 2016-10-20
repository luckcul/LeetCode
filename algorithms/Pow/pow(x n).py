#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-10-20 15:03:47
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

import os

class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        flag = False
        if n < 0: 
        	flag = True
        	n = -n 
        ret = 1.0
        while n != 0:
        	if n&1 == 1 :
        		ret = ret * x
        	x = x*x
        	n = n >> 1
        if flag :
        	ret = 1/ret 
        return ret


if __name__ == "__main__":
	s = Solution()
	print s.myPow(2,-2)