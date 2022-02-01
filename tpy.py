'''
Author: [lxp]
Date: 2021-10-20 13:43:30
LastEditors: [lxp]
LastEditTime: 2022-01-30 10:44:20
Description: 
'''
from typing import List
class Solution:
    
    def helper(self, nums, t):
        res = 0
        
        for n in nums:
            if n == t:
                res += 1
        print("nums: ", nums, " res: ", res)
        return res
    
    def maxScoreIndices(self, nums: List[int]) -> List[int]:
        d = {}
        for i in range(len(nums) + 1):
            left = nums[:i]
            right = nums[i:]
            temp = self.helper(left, 0) + self.helper(right, 1)
            d[i] = temp
        
        ans = []
        maxR = max(d.values())
        for k,v in d.items():
            if v == maxR:
                ans.append(k)
        return ans


s = Solution()
print(s.maxScoreIndices([0,0,1,0]))
