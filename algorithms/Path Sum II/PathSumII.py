#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-01-20 21:40:33
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
	ret = []
	def dfs(self, root, sum, path):
		path.append(root.val)
		if root.left == None and root.right == None :
			if(root.val == sum):
				self.ret.append(list(path))
			return 
		if root.left != None:
			self.dfs(root.left, sum - root.val, list(path))
		if root.right != None:
			self.dfs(root.right, sum - root.val, list(path))

	def pathSum(self, root, sum):
		"""
		:type root: TreeNode
		:type sum: int
		:rtype: List[List[int]]
		"""
		self.ret = []
		if root != None:
			self.dfs(root, sum, [])
		return self.ret 

a = TreeNode(1)
b = TreeNode(2)
c = TreeNode(1)
d = TreeNode(1)
a.left = b 
a.right = c 
c.left = d
print Solution().pathSum(a, 3)