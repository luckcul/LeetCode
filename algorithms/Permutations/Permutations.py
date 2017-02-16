#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-02-15 19:26:46
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    ret = []
    numbers = []
    def dfs(self, s, L) :
        if s == L-1:
            self.ret.append(list(self.numbers))
            return 
        for i in range(s, L):
            self.numbers[s], self.numbers[i] = self.numbers[i], self.numbers[s]
            self.dfs(s+1, L)
            self.numbers[s], self.numbers[i] = self.numbers[i], self.numbers[s]
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        L = len(nums)
        self.numbers = nums
        self.ret = []
        self.dfs(0, L)
        return self.ret

x = Solution()
y = x.permute([1, 2, 3, 4,5])
per = []
for t in y:
    s = ''
    for tx in t:
        s += chr(ord('0') + tx)
    per.append(s)
per.sort()
for t in per:
    print t