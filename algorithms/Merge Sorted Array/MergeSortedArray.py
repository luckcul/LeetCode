#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-10 12:32:46
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        cy = list(nums1)
        i1 = 0
        i2 = 0
        for i in range(m+n):
        	if i1 < m and (i2 >= n or nums1[i1] < nums2[i2]):
        		cy[i] = nums1[i1]
        		i1 += 1
        	else:
        		cy[i] = nums2[i2]
        		i2 += 1
       	for i in range(n+m):
       		nums1[i] = cy[i]
