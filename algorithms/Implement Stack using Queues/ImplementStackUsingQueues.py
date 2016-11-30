#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-30 21:17:38
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12
from collections import deque
class Stack(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.Queue = deque([])

    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self.Queue.append(x)

    def pop(self):
        """
        :rtype: nothing
        """
        l = len(self.Queue)
        if l == 0:
        	return
        for i in range(l-1):
        	tmp = self.Queue.popleft()
        	self.Queue.append(tmp)
        self.Queue.popleft()


    def top(self):
        """
        :rtype: int
        """
        l = len(self.Queue)
        if l == 0:
        	return None
        tmp = 0
        for i in range(l):
        	tmp = self.Queue.popleft()
        	self.Queue.append(tmp)
        return tmp

    def empty(self):
        """
        :rtype: bool
        """
        return True if len(self.Queue) == 0 else False
        