#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-10 13:39:39
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
        last, i, j = n+m-1, m-1, n-1
        while i >= 0 and j >= 0:
        	if nums1[i] > nums2[j]:
        		nums1[last] = nums1[i]
        		i -= 1
        		last -= 1
        	else :
        		nums1[last] = nums2[j]
        		j -= 1
        		last -= 1 
        # not neccesary to deal with i >= 0
        while j >= 0:
        	nums1[last] = nums2[j]
        	last -= 1
        	j -= 1
