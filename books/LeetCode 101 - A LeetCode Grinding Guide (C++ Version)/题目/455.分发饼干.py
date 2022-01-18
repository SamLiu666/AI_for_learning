'''
Author: [lxp]
Date: 2022-01-17 11:15:53
LastEditors: [lxp]
LastEditTime: 2022-01-17 11:21:21
Description: 
'''
#
# @lc app=leetcode.cn id=455 lang=python3
#
# [455] 分发饼干
#

# @lc code=start
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        i, j = 0, 0
        while i < len(g) and j < len(s):
            if s[j] >= g[i]:
                i += 1  # 孩子胃口得到满足
            j += 1  # 饼干的数目总是要增加去满足孩子的胃口
        return i
# @lc code=end

