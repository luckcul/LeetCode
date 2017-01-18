#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-01-18 21:15:14
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12
import math
class Solution(object):
    def arrangeCoins(self, n):
        """
        :type n: int
        :rtype: int
        """
        temp = (math.sqrt(1+8*n)-1)/2
        return int(temp)
print Solution().arrangeCoins(15)