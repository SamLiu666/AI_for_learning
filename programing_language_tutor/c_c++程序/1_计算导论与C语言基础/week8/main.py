'''
Description: 
Version: 2.0
Autor: lxp
Date: 2021-09-04 21:38:13
LastEditors: lxp
LastEditTime: 2021-09-04 21:47:04
'''
import sys

n = sys.stdin.readline()  # string
nums = []
for _ in range(int(n)):
    nums.append(int(sys.stdin.readline()))
print("nums: ", nums)
for temp in nums:
    t1 = 0
    t2 = 0
    t1 += 27 + 23 + temp / 3.0
    t2 = temp / 1.2
    # print("t1, t1", str(t1), str(t2))
    if (t1 < t2):
        print("Bike")
    elif (t1 > t2):
        print("Walk")
    else:
        print("All")
