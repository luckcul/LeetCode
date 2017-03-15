#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-02-17 21:13:15
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    ret = []
    candidates = []
    L = 0
    target = 0
    def dfs(self, index, s, S):
        if s > self.target:
            return  
        if s == self.target:
            self.ret.append(list(S))
        for i in range(index, self.L):
            x = self.candidates[i]
            S.append(x)
            self.dfs(i, s+x, S)
            del S[-1]

    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        self.ret = []
        # sorted(candidates)
        self.candidates = candidates
        self.L = len(candidates)
        self.target = target

        self.dfs(0, 0, [])
        return self.ret 
x = Solution()
print x.combinationSum([2, 3, 6, 7], 7)        