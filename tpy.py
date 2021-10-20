'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-10-20 13:43:30
LastEditors: lxp
LastEditTime: 2021-10-20 13:46:20
'''
from collections import deque
# Definition for a binary tree node.


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrder(self, root: TreeNode):
        if not root:
            return []
        q = deque()
        q.append(root)
        ans = []
        while q:
            temp = []
            qlen = len(q)
            for i in range(qlen):
                node = q.popleft()
                temp.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            ans.append(temp)
        return ans


root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
s = Solution()
print(s.levelOrder(root))
