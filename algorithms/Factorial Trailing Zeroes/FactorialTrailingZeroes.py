#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-01 12:26:22
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        ret = 0
        while n != 0 :
        	n /= 5
        	ret += n 
        return ret

if __name__ == "__main__":
	x = Solution()
	print x.trailingZeroes(122)