#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-01-18 20:42:39
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

# Definition for a binary tree node.
# class TreeNode(object):
# 	def __init__(self, x):
# 		self.val = x
# 		self.left = None
# 		self.right = None

class Solution(object):

	def calHeight(self, root):
		if root == None:
			return 0
		height1 = self.calHeight(root.left)
		height2 = self.calHeight(root.right)
		if height1 < 0 or height2 < 0:
			return -1
		if abs(height1 - height2) > 1:
			return -1
		return max(height1, height2) +1

	def isBalanced(self, root):
		"""
		:type root: TreeNode
		:rtype: bool
		"""
		return False if self.calHeight(root) < 0 else True

if __name__ == "__main__":
	p = TreeNode(1)
	print Solution().isBalanced(p)
