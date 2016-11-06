#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-04 22:15:52
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        return ' '.join(reversed(s.split()))

if __name__ == "__main__":
	x = Solution()
	print [x.reverseWords("")]