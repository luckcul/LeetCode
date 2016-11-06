#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-03 14:15:08
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        v1 = [int(x) for x in version1.split(".")]
        v2 = [int(x) for x in version2.split(".")]
        n = len(v1)
        m = len(v2)
        for i in range(min(n, m)):
        	if v1[i] > v2[i] :
        		return 1
        	elif v1[i] < v2[i]:
        		return -1
        if n == m: 
        	return 0
        elif n > m:
        	for i in range(m, n):
        		if v1[i] != 0:
        			return 1
        	return 0
        else :
        	for i in range(n, m):
        		if v2[i] != 0:
        			return -1
        	return 0

if __name__ == "__main__":
	x = Solution()
	print x.compareVersion("0.1.01.0", "0.1.1")
