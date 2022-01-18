'''
Author: [lxp]
Date: 2022-01-18 10:28:50
LastEditors: [lxp]
LastEditTime: 2022-01-18 10:31:50
Description: 
'''
#
# @lc app=leetcode.cn id=135 lang=python3
#
# [135] 分发糖果
#

# @lc code=start
class Solution:
    def candy(self, ratings) -> int:
        rlen = len(ratings)
        ans = [1 for _ in range(rlen)]  # 存储每一个孩子应得的糖果数量
        
        # 从左往右遍历
        for i in range(rlen - 1):
            print("j: ", i)
            if ratings[i] > ratings[i+1]:
                ans[i] += 1
        print("ans: ", ans)
        # 从右往左遍历
        for i in range(rlen - 1, 0, -1):
            print('i: ', i)
            if ratings[i] > ratings[i-1]:
                ans[i] = max(ans[i], ans[i-1] + 1)
        
        return sum(ans)
# @lc code=end
s = Solution()
print(s.candy([1,2,87,87,87,2,1]))