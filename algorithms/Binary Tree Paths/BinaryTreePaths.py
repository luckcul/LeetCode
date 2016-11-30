#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-29 22:36:40
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {string[]}
    def dfs(self, root, tmp, ret):
    	if root == None:
    		return 
    	tmp = tmp + str(root.val) if len(tmp) == 0 else tmp + "->" + str(root.val)
    	if root.left == None and root.right == None:
    		ret.append(tmp)
    		return 
    	self.dfs(root.left, tmp, ret)
    	self.dfs(root.right, tmp, ret)

    def binaryTreePaths(self, root):
        ret = []
        self.dfs(root, "", ret)
        return ret 
# [1,2,3,null,5]    
print Solution().binaryTreePaths(None)