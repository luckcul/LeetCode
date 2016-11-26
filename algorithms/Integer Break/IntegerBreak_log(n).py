#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-26 20:33:01
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def cal(self, n, x):
        ave = n / x
        ave1 = ave + 1
        s = ave * x 
        sl = n - s 
        cou2 = sl
        cou1 = x - cou2
        return int(pow(ave, cou1) * pow(ave1, cou2))
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: 
        """
        l, r = 2, n
        while l <= r:
            ml = l + (r-l)/3
            mr = r - (r-l)/3
            lans = self.cal(n, ml)
            rans = self.cal(n, mr)
            ret = max(lans, rans)
            if lans <= rans:
                l = ml + 1
            else :
                r = mr - 1
        return ret      