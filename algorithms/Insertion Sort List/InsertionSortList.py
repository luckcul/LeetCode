#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date	: 2017-04-13 15:43:09
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

# Definition for singly-linked list.
class ListNode(object):
	 def __init__(self, x):
		self.val = x
		self.next = None


class Solution(object):
	def insertionSortList(self, head):
		"""
		:type head: ListNode
		:rtype: ListNode
		"""
		p = head
		ret = ListNode(0)
		while p != None:
			temp = ret
			while temp.next and temp.next.val < p.val:
				temp = temp.next
			pnext = p.next
			p.next = temp.next
			temp.next = p
			p = pnext

		return ret.next
