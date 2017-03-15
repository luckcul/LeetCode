#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-03-07 21:58:59
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        ret = None
        last = None
        if l1 == None or l2 == None:
        	if l1 != None : ret = l1
        	if l2 != None : ret = l2
        	return ret
        if l1.val < l2.val:
        	ret = last = l1
        	l1 = l1.next
        else:
        	ret = last = l2
        	l2 = l2.next
        while l1 != None and l2 != None:
        	if l1.val < l2.val:
        		last.next = l1
        		l1 = l1.next
        		last = last.next
        	else:
        		last.next = l2
        		l2 = l2.next
        		last = last.next
        if l1 != None :
        	last.next = l1
        elif l2 != None:
        	last.next = l2
        return ret

