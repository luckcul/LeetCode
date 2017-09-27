#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 17-8-30 下午4:45
# @Author  : luckcul
# @File    : Sum of Square Numbers.py
# @version : 2.7
class Solution(object):
    def isSquare(self, num):
        print num
        return int(num**0.5) ** 2 == num
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        return any([self.isSquare(c - x**2) for x in xrange(0, int(c**0.5) + 1)])