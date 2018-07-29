# 【算法图解】笔记
* 二分查找
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

大O表示法
大O表示法 指的并非是以秒为单位的速度。大O表示法让你能够比较操作数，它指出了算法运行时间的增速。
O(log n) 对数时间 比如二分查找
O(n) 线性时间 比如简单查找
O(n*log n) 快速排序
O(n)
O