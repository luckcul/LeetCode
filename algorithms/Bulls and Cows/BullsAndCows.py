#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-04-20 22:01:14
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        vis1 = [0] * 11
        vis2 = [0] * 11
        numA = 0; numB = 0
        L = len(secret)
        for i in range(L):
        	if secret[i] == guess[i]:
        		numA += 1
        	else:
        		vis1[ord(secret[i]) - ord('0')] += 1
        		vis2[ord(guess[i]) - ord('0')] += 1
        for i in range(10):
        	numB += min(vis1[i], vis2[i])
        ans = str(numA) + 'A' + str(numB) + 'B'
        return ans
