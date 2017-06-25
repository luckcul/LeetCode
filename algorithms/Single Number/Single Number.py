#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-05-21 14:39:08
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

import os
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ret = 0
        for num in nums:
            ret ^= num;
        return ret
        