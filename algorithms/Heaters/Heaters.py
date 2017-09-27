#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 17-9-1 上午9:21
# @Author  : luckcul
# @File    : Heaters.py
# @version : 2.7
class Solution(object):
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        allLoc = []
        allLoc.extend([house, 0] for house in houses)
        allLoc.extend([heater, 1] for heater in heaters)
        allLoc.sort(key=lambda x:x[0])
        ret1 = []
        lastHeater = -1e9
        for loc in allLoc:
            if loc[1] == 1:
                lastHeater = loc[0]
            else:
                ret1.append(loc[0] - lastHeater)
        lastHeater = 2e9
        ret2 = []
        for loc in allLoc[::-1]:
            if loc[1] == 1:
                lastHeater = loc[0]
            else :
                ret2.insert(0, lastHeater - loc[0])
        return max([min(x, y) for x, y in zip(ret1, ret2)])
