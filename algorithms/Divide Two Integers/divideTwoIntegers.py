#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-10-24 22:15:09
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        flag = False
        if dividend * divisor < 0:
            flag = True
        if dividend < 0: dividend = -dividend
        if divisor < 0: divisor = -divisor

        l = 0
        r = dividend
        ret = -1
        while l <= r:
            m = (l+r)/2
            if m*divisor <= dividend:
                l = m+1
                ret = m
            else:
                r = m-1
        if flag:
            ret = -ret 
        if ret >= 2**31: 
            ret = 2**31-1
        return ret

if __name__ == "__main__":
    s = Solution()
    print s.divide(-2147483648,-1)