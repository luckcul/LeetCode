#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-10-20 22:01:16
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12


class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        l = 0
        r = x
        ans = -1
        while l <= r:
            m = (l + r) /2
            if m*m <= x:
                ans = m
                l = m+1
            else :
                r = m-1
        return ans
        

if __name__  == "__main__":
    x = Solution()
    print x.mySqrt(121)
    pass