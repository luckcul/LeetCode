#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-10-30 14:54:23
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        ret = []
        sc1 = ["".join(sorted(x)) for x in strs]
        s = [(sc1[i], i) for i in range(len(sc1))]
        s.sort()
        app = [strs[s[0][1]]]
        for i in range(1, len(s)):
        	if s[i][0] == s[i-1][0]:
        		app.append(strs[s[i][1]])
        	else :
        		ret .append(app)
        		app = [strs[s[i][1]]]
        ret.append(app)
        return ret
if __name__ == "__main__":
	x = Solution()
	print x.groupAnagrams([""])