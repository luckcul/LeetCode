#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-03-08 21:10:25
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.6

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        ret = ListNode(0)
        last = ret
        while True:
            checkFlag = True
            maxVal = 0
            maxId = -1
            for i in range(len(lists)):
                l = lists[i]
                if l != None :
                    checkFlag = False
                    if maxId == -1 or lists[i].val < maxVal:
                        maxId = i 
                        maxVal = lists[i].val
            if checkFlag:
                break 
            last.next = lists[maxId]
            lists[maxId] = lists[maxId].next
            last = last.next
        return ret.next

a = [ListNode(2), ListNode(1)]
x = Solution().mergeKLists(a)
while x :
    print x.val 
    x = x.next