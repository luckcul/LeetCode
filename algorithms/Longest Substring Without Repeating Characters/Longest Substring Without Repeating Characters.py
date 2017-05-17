#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-05-16 15:48:37
# @Author  : luckcul(tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        d = dict()
        ret = 0
        j = -1
        length = len(s)
        for i in range(length):
            while j < length - 1:
                if d.has_key(s[j+1]) and d[s[j+1]] >= 1:
                    break
                j += 1
                if d.has_key(s[j]):
                    d[s[j]] += 1
                else:
                    d[s[j]] = 1
            ret = max(ret, j - i + 1)
            d[s[i]] -= 1
        return ret
