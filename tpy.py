'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-10-20 13:43:30
LastEditors: lxp
LastEditTime: 2021-10-27 14:34:19
'''


class Solution:
    def removeInvalidParentheses(self, s: str):
        def isValid(s):
            count = 0
            for c in s:
                if c == '(':
                    count += 1
                elif c == ')':
                    count -= 1
                    if count < 0:
                        return False
            return count == 0

        ans = []
        currSet = set([s])

        while True:
            for ss in currSet:
                if isValid(ss):
                    ans.append(ss)
            if len(ans) > 0:
                return ans
            nextSet = set()
            for ss in currSet:
                for i in range(len(ss)):
                    if i > 0 and ss[i] == s[i - 1]:
                        continue
                    if ss[i] == '(' or ss[i] == ')':  # 去掉一个括号
                        nextSet.add(ss[:i] + ss[i + 1:])
            currSet = nextSet
        return ans


s = Solution()
print(s.removeInvalidParentheses("()())()"))
