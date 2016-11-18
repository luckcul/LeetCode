#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-10 12:18:00
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        if p == None and q != None or p != None and q == None: 
        	return False
        if p == None and q == None:
        	return True
        if p.val != q.val :
        	return False
        ta = self.isSameTree(p.left, q.left)
        tb = self.isSameTree(p.right, q.right)
        return ta and tb
