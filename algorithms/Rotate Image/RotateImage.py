#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-02-15 15:34:30
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        l = len(matrix) 
        if l == 0: 
            return
        for i in range((l+1)/2):
            for j in range(i, l-i-1):
                ni = i
                nj = j
                tmp = matrix[i][j]
                for t in range(4):
                    nni = nj
                    nnj = l-1-ni
                    a = matrix[nni][nnj]
                    matrix[nni][nnj] = tmp
                    tmp = a
                    ni = nni
                    nj = nnj
