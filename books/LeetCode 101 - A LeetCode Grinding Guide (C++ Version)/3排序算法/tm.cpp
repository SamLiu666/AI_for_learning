/*
 * @Author: [lxp]
 * @Date: 2022-02-06 10:09:54
 * @LastEditors: [lxp]
 * @LastEditTime: 2022-02-08 17:02:10
 * @Description: 
 */
#include <vector>
using namespace std;

// 冒泡排序：O(N^2)，从前往后进行交换，将较大的值放在后面
void bubbleSort(int a[], int N) {
  for (; N > 0; --N) // N iterations
    for (int i = 0; i < N-1; ++i) // except the last, O(N)
      if (a[i] > a[i+1]) // not in non-decreasing order
        swap(a[i], a[i+1]); // swap in O(1)
}

// 选择排序：O(N^2)，从前往后，找到最小值放到第一个未排序部分第一个位置
void selectionSort(int a[], int N) {
  for (int L = 0; L <= N-2; ++L) { // O(N)
    int X = min_element(a+L, a+N) - a; // O(N)
    swap(a[X], a[L]); // O(1), X may be equal to L (no actual swap)
  }
}

// 插入排序：O(N^2)，best-O(N)
void insertionSort(int a[], int N) {
  for (int i = 1; i < N; ++i) { // O(N)
    int X = a[i]; // X is the item to be inserted
    int j = i-1;
    for (; j >= 0 && a[j] > X; --j) // can be fast or slow
      a[j+1] = a[j]; // make a place for X
    a[j+1] = X; // index j+1 is the insertion point
  }
}

void merge(int a[], int low, int mid, int high) {
  // subarray1 = a[low..mid], subarray2 = a[mid+1..high], both sorted
  int N = high-low+1;
  int b[N]; // discuss: why do we need a temporary array b?
  int left = low, right = mid+1, bIdx = 0;
  while (left <= mid && right <= high) // the merging
    b[bIdx++] = (a[left] <= a[right]) ? a[left++] : a[right++];
  while (left <= mid) b[bIdx++] = a[left++]; // leftover, if any
  while (right <= high) b[bIdx++] = a[right++]; // leftover, if any
  for (int k = 0; k < N; ++k) a[low+k] = b[k]; // copy back
}

// 合并排序：O(NlogN)， O(N) storage
void mergeSort(int a[], int low, int high) {
  // the array to be sorted is a[low..high]
  if (low < high) { // base case: low >= high (0 or 1 item)
    int mid = (low+high) / 2;	
    mergeSort(a, low  , mid ); // divide into two halves
    mergeSort(a, mid+1, high); // then recursively sort them
    merge(a, low, mid, high); // conquer: the merge subroutine
  }
}

int partition(int a[], int i, int j) {
  int p = a[i]; // p is the pivot
  int m = i; // S1 and S2 are initially empty
  for (int k = i+1; k <= j; ++k) { // explore the unknown region
    if ((a[k] < p) || ((a[k] == p) && (rand()%2 == 0)))  { // case 2+3
      ++m;
      swap(a[k], a[m]); // C++ STL algorithm std::swap
    } // notice that we do nothing in case 1: a[k] > p
  }
  swap(a[i], a[m]); // final step, swap pivot with a[m]
  return m; // return the index of pivot
}

void quickSort(int a[], int low, int high) {
  if (low < high) {
    int m = partition(a, low, high); // O(N)
    // a[low..high] ~> a[low..m–1], pivot, a[m+1..high]
    quickSort(a, low, m-1); // recursively sort left subarray
    // a[m] = pivot is already sorted after partition
    quickSort(a, m+1, high); // then sort right subarray
  }
}

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