#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-18 21:13:11
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = []
        last = -1
        for c in s:
            if c == " ":
                continue
            if c == ")":
                ans = 0
                stack.append(last)
                last = -1
                ll = stack.pop()
                while len(stack) :
                    tmp = stack.pop()
                    if tmp == "+":
                        ans += ll
                    elif tmp == "-":
                        ans -= ll
                    elif tmp == "(":
                        ans += ll
                        stack.append(ans)
                        break
                    else:
                        ll = tmp
            elif c.isdigit():
                last = int(c) if last < 0 else last * 10 + int(c)            
            else : # + - (
                if last >= 0 :
                    stack.append(last)
                    last = -1
                stack.append(c)
        if last >= 0:
            stack.append(last)
        ret = 0
        ll = 0
        while len(stack):
            tmp = stack.pop()
            if tmp == "+":
                ret += ll
            elif tmp == "-":
                ret -= ll 
            else :
                ll = tmp
        ret += ll
        return ret