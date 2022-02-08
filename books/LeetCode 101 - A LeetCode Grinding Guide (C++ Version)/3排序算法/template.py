'''
Author: [lxp]
Date: 2022-02-01 09:50:28
LastEditors: [lxp]
LastEditTime: 2022-02-08 17:05:02
Description: 
'''

def bubbleSort(arr, n):
    "冒泡排序：O(N^2)，从前往后进行交换"
    while n > 0:
        # 每次都将较大值往后移动，直到有序
        for i in range(n - 1):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i+1], arr[i]
        n -= 1
    return arr

def selectionSort(arr, n):
    "选择排序：O(N^2)，从前往后，找到最小值放到第一个未排序部分第一个位置"
    for i in range(0, n - 1):
        # 每次找出最小值，然后交换最小值下标和当前位置下标
        idx, tempMax = -1, float("inf")
        for j in range(i, n):
            if arr[j] <= tempMax:
                idx = j
                tempMax = arr[j]
        arr[idx], arr[i] = arr[i], arr[idx]
    return arr 

def insertionSort(arr, n):
    "插入排序：O(N^2)，best-O(N)，从后往前找到较小值插入进前面数组中"
    for i in range(1, n):
        # temp 待插入的元素
        temp, j = arr[i], i - 1
        # 找到比当前值小的值插入到前面
        while j >= 0 and arr[j] > temp:
            arr[j + 1] = arr[j]
            j -= 1 
        arr[j + 1] = temp
    return arr


def mergeSort(arr):
    "合并排序：O(NlogN)， O(N) storage"
    if len(arr) > 1:
        mid = len(arr) // 2
        left = arr[:mid]
        right = arr[mid:]
        # Recursive call on each half
        mergeSort(left)
        mergeSort(right)
        # Two iterators for traversing the two halves
        i = 0
        j = 0
        # Iterator for the main list
        k = 0
        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
              # The value from the left half has been used
              arr[k] = left[i]
              # Move the iterator forward
              i += 1
            else:
                arr[k] = right[j]
                j += 1
            # Move to the next slot
            k += 1

        # For all the remaining values
        while i < len(left):
            arr[k] = left[i]
            i += 1
            k += 1

        while j < len(right):
            arr[k]=right[j]
            j += 1
            k += 1

def quickSort(nums):
    "快排"
    def partition(arr,low,high): 
        "默认以最后一个元素为基准值"
        i = ( low-1 )         # 最小元素索引
        pivot = arr[high]     
    
        for j in range(low , high): 
            # 当前元素小于或等于 pivot 
            if arr[j] <= pivot: 
                i = i+1 
                arr[i],arr[j] = arr[j],arr[i] 
    
        arr[i+1],arr[high] = arr[high],arr[i+1] 
        # arr[i+1], pivot = pivot, arr[i+1] 
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
    
    nums = [6,10,2,1,9,3,8,4,7,5]
    #bubbleSort(nums, len(nums))
    #selectionSort(nums, len(nums))
    #insertionSort(nums, len(nums))
    #mergeSort(nums)
    quickSort(nums)
    print(nums)