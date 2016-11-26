#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-26 19:35:56
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = ['A','E','I','O','U','a','e','i','o','u']
        t = []
        ss = list(s)
        for c in s:
        	if c in vowels:
        		t.append(c)
        t.reverse()
        i = 0
        for j in range(len(ss)):
        	if ss[j] in vowels:
        		ss[j] = t[i]
        		i += 1
        return ''.join(ss)
print Solution().reverseVowels('saxce')