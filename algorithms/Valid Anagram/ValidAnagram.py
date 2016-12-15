#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-12-11 15:30:07
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        mark = [0]* 30
        for x in s:
        	temp = ord(x) - ord('a')
        	mark[temp] += 1
        for x in t:
        	temp = ord(x) - ord('a')
        	mark[temp] -= 1
        for i in range(26):
        	if mark[i] != 0:
        		return False
        return True