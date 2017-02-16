#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-02-15 17:18:25
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    ret = []
    def dfs(self, x, n, y, k, t) :
        if k < y :
            self.ret.append(list(t))
            return
        if x > n: 
            return 
        if n-x < k-y:
            return
        self.dfs(x+1, n, y, k, t)
        t.append(x)
        self.dfs(x+1, n, y+1, k, t)
        del t[-1]

    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        self.ret = []
        self.dfs(1, n, 1, k, [])
        return self.ret 
      