#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-10-26 09:32:58
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    mark = [0]*11
    def find(self, k):
        cou = 0
        for i in range(1, 11):
            if self.mark[i] == 0:
                cou += 1
            if cou >= k:
                return i
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        self.mark = [0]*11
        k = k - 1
        l = [0]*(n+2)
        l[0] = 1
        ret = ""
        for i in range(1,n):
            l[i] = l[i-1] * i
        for i in range(n,0, -1):
            tmp = k / l[i-1]
            k -= tmp * l[i-1]
            ai = self.find(tmp + 1)
            self.mark[ai] = 1
            ret += str(ai)
        return ret
