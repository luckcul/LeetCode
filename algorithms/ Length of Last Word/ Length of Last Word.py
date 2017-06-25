#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-25 22:00:02
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        t = s.split(' ')
        t = [x for x in t if x != '']
        if len(t) <= 0:
            return 0
        return len(t[-1])
if __name__ == '__main__':
    x = Solution()
    print x.lengthOfLastWord('a')        