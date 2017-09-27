#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 17-7-13 下午1:11
# @Author  : luckcul
# @File    : Longest Palindromic Substring.py
# @version : 2.7
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        length = len(s)
        maxSubLen = 0
        ret = ""
        for i in range(length):
            add = 0
            while i + add < length and i - add >= 0 and s[i+add] == s[i-add]:
                add += 1
            add -= 1
            if 1 + add * 2 > maxSubLen:
                maxSubLen = 1 + add * 2
                ret = s[i-add : i+add + 1]
            add = 0
            while i-add >= 0 and i + add+1 < length and s[i-add] == s[i+add+1]:
                add += 1
            if add * 2 > maxSubLen:
                maxSubLen = 2 * add
                ret = s[i-add+1 : i+add+1]
        return ret

if __name__ == '__main__':
    x = Solution()
    print x.longestPalindrome('cdbbbbd')