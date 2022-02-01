'''
Author: [lxp]
Date: 2022-02-01 09:50:28
LastEditors: [lxp]
LastEditTime: 2022-02-01 09:58:13
Description: 
'''

class sortTemplates(object):

    def runSort(self, nums, sortName=""):
        return self.sortName(nums)

    def quickSort(self, nums):
        def helper(nums, left, right):
            if left + 1 >= right:
                return
            first, last, key = left, right - 1, nums[first]
            while first < last:
                while first < last and nums[last] >= key:
                    last -= 1
                nums[first] = nums[last]

                while first < last and nums[first] <= key:
                    first += 1
                nums[last] = nums[first]
                    