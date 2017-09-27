#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 17-7-11 下午1:38
# @Author  : luckcul
# @File    : Burst Balloons.py
# @version : 2.7
class Solution(object):
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        nums = [1,] + nums + [1,]
        length = len(nums)
        dp = [[0] * length for i in range(length)]
        # for i in range(length - 2):
        #     dp[i][i+2] = nums[i] * nums[i+1] * nums[i+2]
        for i in range(2, length):
            for j in range(length - i):
                l = j
                r = j + i
                for k in range(l+1, r):
                    dpLeft = dp[l][k] if k-l > 1 else 0
                    dpRight = dp[k][r] if r - k > 1 else 0
                    dp[l][r] = max(dp[l][r], dpLeft + dpRight + nums[l]*nums[k]*nums[r])
        return dp[0][length - 1]


if __name__ == '__main__':
    x = Solution()
    print x.maxCoins([7,9,8,0,7,1,3,5])