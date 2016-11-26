#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-21 12:35:25
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

# NOTICE : THIS SOLUTION GOT "TLE"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
class Solution(object):
    def getOpe(self, x):
        if x == 0:
            return ''
        elif x == 1:
            return '+'
        elif x == 2:
            return '-'
        else:
            return '*'
    def calcute(self, s):
        ret = 0
        SUM = 0
        ADD = True
        PRO = 1
        flag = True
        last = -1
        for c in s:
            isd = c.isdigit()
            if isd :
                tmp = int(c)
                if last == 0:
                    continue
                last = (tmp if last < 0 else last * 10 + tmp)
            elif c == '*':
                PRO = PRO * last
                flag = False
                last = -1
            else:
                if flag == False:
                    last = PRO * last
                SUM = SUM + (last if ADD else -last)
                ADD = (c == '+')
                flag = True
                last = -1
        if flag == False:
            last = PRO * last
        SUM = SUM + (last if ADD else -last)
        return SUM


    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """
        n = len(num)
        #[1,n]
        ret = []
        tot = (1<<((n-1)*2))
        for sta in range(0, tot):
            num_ = list(num)
            st = sta
            # print st, "....."
            for i in range(n-1, -1, -1):
                x = st & 1
                st = st >> 1
                x = x*2 + (st & 1)
                st = st >> 1
                char = self.getOpe(x)
                # print i, char
                if char == '': continue
                num_.insert(i, char)
            num_ = "".join(num_)
            ans = self.calcute(num_)
            if ans == target:
                ret.append(num_)
        return ret 

# print Solution().calcute('2*3+2')
print Solution().addOperators("123456789",45)        