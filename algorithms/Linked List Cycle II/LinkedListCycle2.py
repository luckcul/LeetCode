#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-05 18:38:35
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# O(n*CycleLength) is too slow
class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        p1 = head
        p2 = head
        cou = 0
        while cou < 1:
        	if p2 == None:
        		break
        	p2 = p2.next
        	if p2 == None:
        		break
        	p2 = p2.next
        	if p1 ==  None:
        		break
        	p1 = p1.next
        	if p1 == p2:
        		cou += 1
        if cou != 1:
        	return 
        cycleLen = 1
        while True:
        	p2 = p2.next
        	p2 = p2.next
        	p1 = p1.next
        	if p1 == p2:
        		break
        	cycleLen += 1
        p1 = head
        while True:
        	p2 = p1
        	for i in range(cycleLen):
        		p2 = p2.next
        	if p2 == p1:
        		break
        	p1 = p1.next
        return p1