#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-06 22:39:04
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        p1 = head
        p2 = head
        while True :
        	if p2 == None:
        		break
        	p2 = p2.next
        	if p2 == None:
        		break
        	p2 = p2.next
        	if p1==None:
        		break
        	p1 = p1.next
        	if p1 == p2:
        		break
        if p1 != p2:
        	return
        p1 = head
        while True:
        	if p1 == p2:
        		break
        	p1 = p1.next
        	p2 = p2.next
        return p1
