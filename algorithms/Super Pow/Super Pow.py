#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-10-20 15:15:36
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

import os
class Solution(object):
	def myPow(self, a, b): # b < 10
		ret = 1
		for i in range(b):
			ret *= a
		return ret

	def superPow(self, a, b):
		"""
		:type a: int
		:type b: List[int]
		:rtype: int
		"""
		length = len(b)
		mod = 1337 #mod
		ret = 1
		for i in range(length-1, -1, -1):
			ret *= self.myPow(a,b[i])
			ret %= mod
			a = self.myPow(a,10)
			a %= mod
		return ret

if __name__ == "__main__" :
	s = Solution()
	print s.superPow(2,[1,1])
	pass