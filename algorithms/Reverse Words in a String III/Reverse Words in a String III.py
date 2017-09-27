#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 17-7-11 下午7:49
# @Author  : luckcul
# @File    : Reverse Words in a String III.py
# @version : 2.7
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        return ' '.join(si[::-1] for si in s.split(' '))