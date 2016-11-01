#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-01 13:32:01
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n <= 0 : return False
        return True if (1<<30)%n == 0 else False
