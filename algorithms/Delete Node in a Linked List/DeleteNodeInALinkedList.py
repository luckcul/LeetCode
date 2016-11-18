#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-18 12:31:53
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        p = node.next
        node.val = p.val
        node.next = p.next

