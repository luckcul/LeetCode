#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 17-9-14 下午1:29
# @Author  : luckcul
# @File    : Number of Segments in a String.py
# @version : 2.7
class Solution(object):
    def countSegments(self, s):
        """
        :type s: str
        :rtype: int
        """
        return len(filter(None,s.strip(' ').split(' ')))