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
#### 数组和链表
##### 数组的特点
* 在内存中，数组是一块连续的区域。
* 数组需要预留空间，在使用前要先申请占内存的大小，可能会浪费内存空间。
* 插入数据和删除数据效率低，插入数据时，这个位置后面的数据在内存中都要向后移。删除数据时，这个数据后面的数据都要往前移动。
* 随机读取效率很高。因为数组是连续的，知道每一个数据的内存地址，可以直接找到给地址的数据。
* 不利于扩展，数组定义的空间不够时要重新定义数组。
##### 链表的特点
* 在内存中可以存在任何地方，不要求连续。
* 每一个数据都保存了下一个数据的内存地址，通过这个地址找到下一个数据。
* 增加数据和删除数据很容易。
* 查找数据时效率低，因为不具有随机访问性。
* 不指定大小，扩展方便。链表大小不用定义，数据随意增删。

下面是常见数组和链表的运行时间

| |数组|链表|
|:---|:---|:---|
|读取|O(1)|O(n)|
|插入|O(n)|O(1)|
|删除|O(n)|O(1)|

##### O(n) = 线性时间
##### O(1) = 常量时间