#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-30 21:13:57
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Queue(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []

    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self.stack.append(x)

    def pop(self):
        """
        :rtype: nothing
        """
        sta = []
        l = len(self.stack)
        for i in range(l):
        	tmp = self.stack.pop()
        	sta.append(tmp)
        sta.pop()
        for i in range(l-1):
        	tmp = sta.pop()
        	self.stack.append(tmp)

    def peek(self):
        """
        :rtype: int
        """
        sta = []
        l = len(self.stack)
        for i in range(l):
        	tmp = self.stack.pop()
        	sta.append(tmp)
        ret = sta.pop()
        self.stack.append(ret)
        for i in range(l-1):
        	tmp = sta.pop()
        	self.stack.append(tmp)
        return ret

    def empty(self):
        """
        :rtype: bool
        """
        return True if len(self.stack)==0 else False

x = Queue()
x.push(1)
x.push(2)
print x.peek()
x.pop()
print x.peek()
print x.empty()
x.pop()
print x.empty()