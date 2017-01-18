#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-01-18 21:39:19
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        ret = True
        for i in range(0, 9):
            vis = [0]*10
            for j in range(0, 9):
                if board[i][j] == '.':
                    continue
                if vis[int(board[i][j])] == 1:
                    ret = False
                vis[int(board[i][j])] = 1
        if ret == False:
            return False
        for j in range(0, 9):
            vis = [0] * 10
            for i in range(0, 9):
                if board[i][j] == '.':
                    continue
                if vis[int(board[i][j])] == 1:
                    ret = False
                vis[int(board[i][j])] = 1
        if ret == False:
            return False
        x = 0
        y = 0
        for addx in range(0, 9, 3):
            for addy in range(0, 9, 3):
                x = addx
                y = addy
                vis = [0]*10
                for i in range(0, 3):
                    for j in range(0, 3):
                        nx = x+i 
                        ny = y + j
                        if board[nx][ny] == '.':
                            continue
                        if vis[int(board[nx][ny])] == 1:
                            ret = False
                        vis[int(board[nx][ny])] = 1
        return ret


        	
