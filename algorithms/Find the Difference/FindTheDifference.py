#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-12-13 22:46:47
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        s = sorted(s)
        t = sorted(t)
        l = len(s)
        for i in range(l):
        	if t[i] != s[i]:
        		return t[i]
        return t[-1]

