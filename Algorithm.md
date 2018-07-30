# 【算法图解】笔记
#### 二分查找
```
def binary_search(list,item):
    low = 0
    high = len(list)-1
    
    while low <= high:
        mid = (low + high)
        guess = list[mid]
        if guess == item:
            return mid
        elif guess > item:
            high = mid - 1
        else:
            low = mid + 1
    return None

```
一般来说 对于包括n个元素的列表，用二分查找最多需要log n(以2为底)步，而简单查找最多需要n步。

#### 大O表示法
大O表示法 指的并非是以秒为单位的速度。大O表示法让你能够比较操作数，它指出了算法运行时间的增速。
* O(log n) 对数时间 比如二分查找
* O(n) 线性时间 比如简单查找
* O(n*log n) 快速排序
* O(n*n) 选择排序
* O(n!) 旅行商问题

#### 选择排序
选择排序（Selection sort）是一种简单直观的排序算法。它的工作原理是每一次从待排序的数据元素中选出最小（或最大）的一个元素，存放在序列的起始位置，直到全部待排序的数据元素排完。
##### 例: 将一个音乐播放列表按播放次数从多到少的顺序排列。
##### 解: 遍历这个列表，找出播放最多的歌曲，并将歌曲添加到一个新列表，直到全部待排序的数据元素排完。
```
def findSmallest(arr):
    samllest = arr[0]
    smallest_index = 0
    for i in range(1,len(arr)):
        if arr[i] < smallest:
            smallest_index = i
    return smallest_index
    
def selectionSort(arr):
    newArr = []
    for i in range(len(arr)):
        smallest = findSmallest(arr)
        newArr.append(arr.pop(smallest))
    return newArr
```