#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-12-15 22:39:59
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        n=len(ratings)
        l=[1]*n
        r=[1]*n
        for i in range(1,n):
            if ratings[i]>ratings[i-1]:
                l[i]=l[i-1]+1
        for i in range(n-2,-1,-1):
            if ratings[i]>ratings[i+1]:
                r[i]=r[i+1]+1
        ret=0
        for i in range(n):
            ret += max(l[i],r[i])
        return ret
