#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-02-22 21:14:26
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    ret = []

    def dfs(self,num, nowNum, nowSum, n, k, temp):
        if nowSum == n and num == k:
            self.ret.append(list(temp))
            return 
        if nowNum >= n or nowNum > 9 or num > k:
        	return
        if nowNum > 9:
        	return 
        for i in range(nowNum, 10):
        	temp.append(i)
        	self.dfs(num+1, i+1, nowSum+i, n, k, temp)
        	del temp[-1]
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        self.ret = []
        self.dfs(0, 1, 0, n, k, [])
        return self.ret
x = Solution()
print x.combinationSum3(4, 15)