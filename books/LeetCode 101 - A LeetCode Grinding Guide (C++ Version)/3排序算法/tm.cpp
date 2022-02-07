/*
 * @Author: [lxp]
 * @Date: 2022-02-06 10:09:54
 * @LastEditors: [lxp]
 * @LastEditTime: 2022-02-06 10:18:13
 * @Description: 
 */
#include <vector>
using namespace std;

vector<int> quick_sort(vector<int> &nums, int left, int right) {
    if (left + 1 >= right) {return;}
    // 默认以第一个元素为基准值
    int first = left, last = right, pivot = nums[first]; 
    while (first < last) {
        while (first < right && nums[last] >= pivot) {
            //先从后往前遍历，比基准值大的元素不动
            last--;
        }
        nums[first] = nums[last];  // 找到了比基准值小的值，交换
        while (first < right && nums[first] <= pivot) {
            // 从前往后遍历，比基准值大的元素不动
            first++;
        }
        nums[last] = first;
    }
    nums[first] = pivot;
    quick_sort(nums, left, first);
    quick_sort(nums, first + 1, right);
}



void sort() {
    vector<int> nums = {1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0};
    vector<int> temp(nums.size());
    sort(nums.begin(), nums.end());
    quick_sort(nums, 0, nums.size());
    merge_sort(nums, 0, nums.size(), temp);
    insertion_sort(nums, nums.size());
    bubble_sort(nums, nums.size());
    selection_sort(nums, nums.size());
}
int main() {

    return 0;
}