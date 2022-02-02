'''
Author: [lxp]
Date: 2022-02-01 09:50:28
LastEditors: [lxp]
LastEditTime: 2022-02-02 09:59:54
Description: 
'''

class sortTemplates(object):

    def printNums(self, nums):
        for n in nums:
            print(n, end=" ")
        print()

    def runSort(self, nums, sortName=None):
        """排序模板--调用使用名称

        Args:
            nums (list(int)): [数组]
            sortName (str, optional): [排序算法名称: quickSort]. Defaults to "".

        Returns:
            [list(int)]: [已排序的数组]
        """
        self.printNums(nums)
        numsSorted = sortName(nums)
        self.printNums(nums) 

    def quickSort(self, nums):
        "快排"
        def partition(arr,low,high): 
            i = ( low-1 )         # 最小元素索引
            pivot = arr[high]     
        
            for j in range(low , high): 
        
                # 当前元素小于或等于 pivot 
                if   arr[j] <= pivot: 
                
                    i = i+1 
                    arr[i],arr[j] = arr[j],arr[i] 
        
            arr[i+1],arr[high] = arr[high],arr[i+1] 
            return ( i+1 ) 
        
        def quick(arr,low,high): 
            """ # arr[] --> 排序数组
                # low  --> 起始索引
                # high  --> 结束索引"""
            if low < high: 
        
                pi = partition(arr,low,high) 
        
                quick(arr, low, pi-1) 
                quick(arr, pi+1, high) 
        quick(nums, 0, len(nums) - 1)
        return nums


if __name__ == "__main__":
    s = sortTemplates()
    nums = [6,10,2,1,9,3,8,4,7,5]
    s.runSort(nums, sortName=s.quickSort)
