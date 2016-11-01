#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-01 13:32:27
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

import math

class Solution(object):
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 0: return False
        tmp = math.log(num) / math.log(4)
        if math.fabs(tmp - int(tmp)) <= 0.000001:
        	return True
        else: return False
if __name__ == "__main__":
	x = Solution()
	print x.isPowerOfFour(-1)