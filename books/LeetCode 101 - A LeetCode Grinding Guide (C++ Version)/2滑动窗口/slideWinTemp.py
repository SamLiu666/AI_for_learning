'''
Author: [lxp]
Date: 2022-01-25 10:16:40
LastEditors: [lxp]
LastEditTime: 2022-01-25 10:42:14
Description: 
'''
# ! 滑动窗口模板

def findSubString(s, t):
    """滑动窗口模板 找出s中的t字串

    Args:
        s ([string]): [主字符串]
        t ([string]): [子字符串]
    """
    dic, winCurDic = {}, {}  # 字典存储t中， 当前窗口字典
    begin, end = 0, 0  # 双指针
    flag, req = 0, len(t)  # 有效标志位，原始字符串req长度
    for c in t:
        # 初始化字串哈希表
        dic[c] = dic.get(c, 0) + 1
    ans = float("inf"), None, None  # 可用元组存储结果
    while end < len(s):
        # Add one character from the right to the window
        winCurDic[s[end]] = winCurDic.get(s[end], 0) + 1

        # If the frequency of the current character added equals to the desired count in t then increment the formed count by 1.
        if ...:
            flag += 1

        # Try and contract the window till the point where it ceases to be 'desirable'.
        while begin <= end and flag == req:
            ...
            # 记录长度
            begin += 1
        end += 1