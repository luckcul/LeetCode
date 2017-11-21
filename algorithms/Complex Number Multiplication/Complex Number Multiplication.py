#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 17-10-12 上午10:59
# @Author  : luckcul
# @File    : Complex Number Multiplication.py
# @version : 2.7
class Solution(object):
    def complexNumberMultiply(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        aL = a.split("+")
        bL = b.split("+")
        a1 = int(aL[0])
        a2 = int(aL[1][:-1])
        b1 = int(bL[0])
        b2 = int(bL[1][:-1])
        ret1 = a1 * b1 - a2 * b2
        ret2 = a1 * b2 + a2 * b1
        return str(ret1) + "+" + str(ret2) + "i"