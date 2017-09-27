#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 17-6-29 下午9:51
# @Author  : luckcul
# @File    : Rectangle Area.py
# @version : 2.7
class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        """
        :type A: int
        :type B: int
        :type C: int
        :type D: int
        :type E: int
        :type F: int
        :type G: int
        :type H: int
        :rtype: int
        """
        # (A, B) (C, D) AND (E, F) (G, H)
        xMin = max(A, E)
        xMax = min(C, G)
        yMin = max(B, F)
        yMax = min(D, H)
        x = max(0, xMax - xMin)
        y = max(0, yMax - yMin)
        area1 = abs(A - C) * abs(B - D)
        area2 = abs(E - G) * abs(F - H)
        # print area1, area2, x, y
        return area1 + area2 -  x * y
x = Solution()
x.computeArea(-2, -2, 2, 2, 3, 3, 4, 4)