#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-18 22:30:45
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        last = -1
        ans = 0
        flag = True
        SUM = 0
        add = True
        PRO = 1
        mul = True
        for c in s:
        	if c == " ":
        		continue
        	if c.isdigit():
        		last = int(c) if last < 0 else last * 10 + int(c)
        	elif c == "+" or c == "-":
        		if flag:
        			SUM = SUM + (last if add else -last)
        		else:
        			tmp = PRO*last if mul else PRO/last
        			SUM = SUM + (tmp if add else - tmp)
        		add = (c == "+")
        		PRO = 1
        		mul = True
        		flag = True
        		last = -1
        	else :
        		PRO = PRO*last if mul else PRO/last
        		mul = (c == "*")
        		flag = False
        		last = -1
        if flag:
        	SUM = SUM + (last if add else -last)
        else :
        	tmp = PRO*last if mul else PRO/last
        	SUM = SUM + (tmp if add else -tmp)
        return SUM