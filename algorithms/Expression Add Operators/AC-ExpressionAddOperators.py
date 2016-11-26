#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-21 14:15:57
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """
        ret = []
        self.search(num, target, 0, 0, "", ret)
        return ret

    def search(self, num, target, lastOpt, result, expression, ret):
    	if len(num) == 0:
    		if target == result:
    			ret.append(expression)
    		return

    	for i in range(1, len(num)+1):
    		cur = num[:i]
    		left = num[i:]
    		if i>1 and cur[0] == '0':
    			continue
    		curVal = int(cur)
    		if len(expression) == 0:
    			self.search(left, target, curVal, curVal, expression + cur, ret)
    		else :
    			self.search(left, target, curVal, result + curVal, expression+"+"+cur, ret)
    			self.search(left, target, -curVal, result - curVal, expression+"-"+cur, ret)
    			self.search(left, target, curVal*lastOpt, result - lastOpt + curVal*lastOpt, expression + "*" + cur, ret)

print Solution().addOperators("3456237490",9191)          			