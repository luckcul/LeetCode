#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 17-7-28 上午11:23
# @Author  : luckcul
# @File    : Simplify Path.py
# @version : 2.7


class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        pathList = path.split('/')
        pathList = [pathi for pathi in pathList if pathi != '']
        stack = []
        for pathi in pathList:
            if pathi == '.':
                continue
            elif pathi == '..':
                if len(stack) > 0:
                    stack.pop()
            else:
                stack.append(pathi)
        return '/' + '/'.join(stack)

if __name__ == '__main__':
    x = Solution()
    print x.simplifyPath("/a/./b/../..//c/../..")