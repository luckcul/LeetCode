#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2016-11-02 16:31:49
# @Author  : luckcul (tyfdream@gmail.com)
# @Version : 2.7.12

class Solution(object):
    vis = [[]]
    grid = [[]]
    dire = [[1, 0], [-1, 0], [0, 1], [0, -1]]
    n = 0
    m = 0
    def dfs(self, i, j):
        self.vis[i][j] = 1
        for k in range(4):
            dx = self.dire[k][0]
            dy = self.dire[k][1]
            x = i + dx
            y = j + dy
            if x < 0 or x >= self.n or y < 0 or y >= self.m :
                continue
            if self.vis[x][y] ==1 or self.grid[x][y] == 0:
                continue
            self.dfs(x, y)
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        grid = [[ 1 if y== "1" else 0 for y in x]for x in grid]
        self.grid = grid
        self.n = len(grid)
        if self.n == 0: 
            return 0
        self.m = len(grid[0])
        self.vis = [[0]*self.m for i in range(self.n)]
        ret = 0
        for i in range(self.n):
            for j in range(self.m):
                if self.vis[i][j] == 1 or grid[i][j] == 0:
                    continue
                else:
                    ret += 1
                    self.dfs(i, j)
        return ret


if __name__ == "__main__":
    x = Solution()
    # print x.numIslands([])
    print x.numIslands(["110", "100", "001"])