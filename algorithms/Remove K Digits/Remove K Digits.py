#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 17-7-4 下午7:52
# @Author  : luckcul
# @File    : Remove K Digits.py
# @version : 2.7
class Solution(object):
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        num = '0' + num + '0'
        nowIndex = 1
        length = len(num)
        hasChanged = 0
        while hasChanged < k:
            if num[nowIndex] < num[nowIndex-1]:
                hasChanged += 1
                num = num[:nowIndex-1] + num[nowIndex:]
                nowIndex -= 1
            else:
                nowIndex += 1
                if nowIndex > len(num)-1:
                    break
        num = num[:-1]
        while len(num) >= 1 and num[0] == '0':
            num = num[1:]
        if len(num) == 0:
            num = '0'
        return num
if __name__ == '__main__':
    x = Solution()
    print x.removeKdigits('10', 2)
