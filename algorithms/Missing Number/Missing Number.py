#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-05-21 14:44:07
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

import os
class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        s = sum(nums)
        return (1+length)*length/2 - s
