#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-01 13:14:57
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        #max num 3**i == 1162261467
        if n <= 0: return False
        return True if 1162261467%n == 0 else False

if __name__ == "__main__":
	x = Solution()
	print x.isPowerOfThree(6)