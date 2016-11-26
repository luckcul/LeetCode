#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-26 14:58:15
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        nums1.sort()
        nums2.sort()
        l1 = len(nums1)
        l2 = len(nums2)
        i,j = 0, 0
        ret = []
        while i < l1 and j < l2 :
        	if nums1[i] == nums2[j]:
        		ret.append(nums1[i])
        		i += 1
        		j += 1
        	elif nums1[i] > nums2[j]:
        		j += 1
        	else :
        		i += 1
        return ret
print Solution().intersect([1,2,2,1],[2,2])