#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-05 17:04:49
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        p1 = head
        p2 = head
        cou = 0
        while cou < 1:
        	if p2 == None:
        		break
        	p2 = p2.next
        	if p2 ==None :
        		break
        	p2 = p2.next
        	if p1 == None:
        		break
        	p1 = p1.next
        	if p1 == p2 :
        		cou += 1
        return True if cou == 1 else False
