#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-10-20 22:13:02
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12


class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        flag = False
        l = 0
        r = num
        while l <= r:
            m = (l+r) / 2
            if m*m == num:
                flag = True
                break
            elif m*m < num:
                l = m+1
            else:
                r = m-1
        return flag
if __name__ == "__main__":
    x = Solution()
    print x.isPerfectSquare(99)