#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-12-08 14:41:40
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if root == None :
        	return None
        if root == p or root == q:
        	return root
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        if root == 37:
        	print left, right
        if left != None and right != None:
        	return root
        elif left != None:
        	return left
        elif right != None:
        	return right
        else :
        	return None
