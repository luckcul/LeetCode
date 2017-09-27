#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 17-9-7 下午12:54
# @Author  : luckcul
# @File    : Integer to English Words.py
# @version : 2.7
class Solution(object):
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0: return "Zero"
        m1 = ["One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
              "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
        m3 = ["Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
        m4 = ["", "Thousand", "Million", "Billion"]
        ret = ""
        count = 0
        while num != 0:
            nowNum = num % 1000
            num /= 1000
            nowStr = ""
            hundred = nowNum / 100
            if hundred != 0 :
                nowStr += m1[hundred-1] + " " + "Hundred "
            lowerTwo = nowNum % 100
            if lowerTwo < 20 and lowerTwo > 0:
                nowStr += m1[lowerTwo-1] + " "
            elif lowerTwo >= 20 :
                twoUnit = lowerTwo / 10
                unit = lowerTwo % 10
                nowStr += m3[twoUnit - 2] + " "
                if unit != 0:
                    nowStr += m1[unit - 1] + " "
            if nowNum != 0: nowStr += m4[count] + " "
            # nowStr +=  " "
            ret = nowStr + ret
            count += 1
        return ret.strip()


