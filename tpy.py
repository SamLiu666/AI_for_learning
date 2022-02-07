'''
Author: [lxp]
Date: 2021-10-20 13:43:30
LastEditors: [lxp]
LastEditTime: 2022-02-07 12:10:20
Description: 
'''
from typing import List
class Solution:
    
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        ans = []
        cnt = [[a, 'a'], [b, 'b'], [c, 'c']]
        while True:
            cnt.sort(key=lambda x: -x[0])
            hasNext = False
            for i, (c, ch) in enumerate(cnt):
                if c <= 0:
                    break
                if len(ans) >= 2 and ans[-2] == ch and ans[-1] == ch:
                    continue
                hasNext = True
                ans.append(ch)
                cnt[i][0] -= 1
                break
            if not hasNext:
                return ''.join(ans)
s = Solution()
print(s.longestDiverseString(2,2,1))

print("d ")