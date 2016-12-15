#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-12-08 14:16:56
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if root.val == p.val or root.val == q.val:
        	return root
        if (root.val > p.val and root.val < q.val) or (root.val < p.val and root.val > q.val):
        	return root
        if root.val > p.val and root.val > q.val :
        	return self.lowestCommonAncestor(root.left, p, q)
        if root.val < p.val and root.val < q.val :
        	return self.lowestCommonAncestor(root.right, p, q)
root = TreeNode(2)
a = TreeNode(1)
b = TreeNode(3)
root.left = a
root.right = b
print Solution().lowestCommonAncestor(root, TreeNode(3), TreeNode(1)).val