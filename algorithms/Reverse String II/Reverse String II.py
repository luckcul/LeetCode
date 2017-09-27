#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 17-7-11 下午7:23
# @Author  : luckcul
# @File    : Reverse String II.py
# @version : 2.7
class Solution(object):
    def reverseStr(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        return ''.join([s[x:min(len(s), x+k)][::-1] if x % (2*k) == 0 else s[x:min(len(s), x+k)] for x in range(0, len(s), k)])
x = Solution()
print x.reverseStr('abcdefghijklmnop',4)