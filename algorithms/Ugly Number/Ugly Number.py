#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 17-6-30 上午9:26
# @Author  : luckcul
# @File    : Ugly Number.py
# @version : 2.7
class Solution(object):
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 0: return False
        factor = [2, 3, 5]
        for fac in factor:
            while num % fac == 0:
                num /= fac
        return True if num == 1 else False