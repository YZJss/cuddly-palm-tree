# 【算法图解】笔记
#### 二分查找
首先，假设表中元素是按升序排列，将表中间位置记录的关键字与查找关键字比较，如果两者相等，则查找成功；否则利用中间位置记录将表分成前、后两个子表，如果中间位置记录的关键字大于查找关键字，则进一步查找前一子表，否则进一步查找后一子表。重复以上过程，直到找到满足条件的记录，使查找成功，或直到子表不存在为止，此时查找不成功。  
**列表必须采用顺序存储结构。**
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
* O(log n) 对数时间 比如[二分查找](https://github.com/YZJss/note/blob/master/Algorithm.md#%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE)
* O(n) 线性时间 比如简单查找
* O(n*log n) [快速排序](https://github.com/YZJss/note/blob/master/Algorithm.md#%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F)
* O(n*n) [选择排序](https://github.com/YZJss/note/blob/master/Algorithm.md#%E9%80%89%E6%8B%A9%E6%8E%92%E5%BA%8F)
* O(n!) 旅行商问题  
#### 小结  
* 二分查找的速度比简单查找快得多
* O(log n) 比 O(n)快。需要搜索的元素越多，前者比后者就越快的越多。
* 算法运行时间并不以秒为单位。
* 算法运行时间是从其增速的角度度量的
* 算法运行时间用大O表示法表示。
***
#### 选择排序
选择排序（Selection sort）是一种简单直观的排序算法。它的工作原理是每一次从待排序的数据元素中选出最小（或最大）的一个元素，存放在序列的起始位置，直到全部待排序的数据元素排完。  
例: 将一个音乐播放列表按播放次数从多到少的顺序排列。  
解: 遍历这个列表，找出播放最多的歌曲，并将歌曲添加到一个新列表，直到全部待排序的数据元素排完。
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

O(n) = 线性时间  
O(1) = 常量时间
#### 小结
* 需要存储多个元素时，可使用数组或链表。
* 数组的元素都在一起
* 链表的元素是分开的，其中每个元素都存储了下一个元素的地址。
* 数组的读取速度很快，链表的插入和删除速度很快。
* 在同一个数组中，所有元素的类型必须相同（都为int double等）。
***
#### 递归
程序调用自身的编程技巧称为递归（recursion）。
```
def countdown(i):
    print(i)
    countdown(i-1)
```
这样输出3...2...1...0...-1...-2...会导致无限循环，所以编写递归函数时，必须告诉它何时停止递归。正因为如此，每个函数都有俩部分：基线条件（base case）和递归条件（recursive case）。递归条件指的是函数调用自己，而基线条件则指的是函数不在调用自己，从而避免形成无限循环。  
```
def countdown(i):
    print(i)
    if i <= 0:  #基线条件
        return
    else:       #递归条件
    countdown(i-1)
```
#### 栈
栈作为一种数据结构，是一种只能在一端进行插入和删除操作的特殊线性表。它按照先进后出的原则存储数据，先进入的数据被压入栈底，最后的数据在栈顶，需要读数据的时候从栈顶开始弹出数据（最后一个数据被第一个读出来）。栈具有记忆作用，对栈的插入与删除操作中，不需要改变栈底指针。  
比如**一叠便条**插入待办事项放在最前面；读取待办事项时，你只读取最上面的那个，并将其删除。因此这个待办事项清单只有俩种操作：压入（插入）和弹出（删除并读取）。  
#### 小结
* 递归指的是调用自己的函数。
* 每个递归函数都有俩个条件：基准条件和递归条件。
* 栈有俩种操作：压入和弹出。
* 所有函数调用都进入调用栈。
* 调用栈可能很长，这将占用大量的内存。
***
#### 快速排序
设要排序的数组是A[0]……A[N-1]，首先任意选取一个数据（通常选用数组的第一个数）作为关键数据，然后将所有比它小的数都放到它前面，所有比它大的数都放到它后面，这个过程称为一趟快速排序。值得注意的是，快速排序不是一种稳定的排序算法，也就是说，多个相同的值的相对位置也许会在算法结束时产生变动
```
def quicksort(array):
    if len(array) < 2:
        return array
    else:
        pivot = array[0]
        less = [i for i in array[1:] if i <= pivot]
        greater = [i for i in array[1:] if i > pivot]
        return quicksort(less) + [pivot] + quicksort(greater)
```
***
#### 散列表
散列表（Hash table，也叫哈希表），是根据关键码值(Key value)而直接进行访问的数据结构。也就是说，它通过把关键码值映射到表中一个位置来访问记录，以加快查找的速度。这个映射函数叫做散列函数，存放记录的数组叫做散列表。  
python提供的散列表实现为字典**dict()**  
#### 小结
* 散列表的查找、插入和删除都非常快
* 散列表适合用于模拟映射关系
* 散列表可用于缓存数据（例如，在Web服务器上）
* 散列表非常适合用于防止重复
***
#### 广度优先搜索
宽度优先搜索算法（又称广度优先搜索）是最简便的图的搜索算法之一，这一算法也是很多重要的图的算法的原型。Dijkstra单源最短路径算法和Prim最小生成树算法都采用了和宽度优先搜索类似的思想。其别名又叫BFS，属于一种盲目搜寻法，目的是系统地展开并检查图中的所有节点，以找寻结果。换句话说，它并不考虑结果的可能位置，彻底地搜索整张图，直到找到结果为止。  
#### 队列
队列是一种特殊的线性表，特殊之处在于它只允许在表的前端（front）进行删除操作，而在表的后端（rear）进行插入操作，和栈一样，队列是一种操作受限制的线性表。进行插入操作的端称为队尾，进行删除操作的端称为队头。队列只支持俩种操作：**入队和出队**。  
队列是一种先进先出(First In First Out FIFO)的数据结构，而栈是一种后进后出(Last In First Out LIFO)的数据结构。  
  
假如你经营着一个芒果农场，需要寻找芒果销售商，以便将芒果卖给他。你则需在你的朋友中查找。  
首先，创建一个朋友名单。然后，依次检查名单中的每个人，看看他是否是芒果经销商。假如你没有朋友是芒果销售商，那么你就必须在朋友的朋友中查找。检查名单中的每个人时，你都将其朋友加入名单。使用这种算法将搜遍你的整个人际关系网，直到找到芒果经销商，这就是广度优先搜索算法。
```
from collections import deque
def person_is_seller(name):
    return name[-1] == 'm'      #判断一个人是不是芒果经销商，这个函数检查人的姓名是否以m结尾：如果是，他就是芒果经销商。这种判断方法有点搞笑，但这个示例而言是可行的。
def search(name):
    search_queue = deque()      #创建队列
    search_queue += graph[name]     #将自己的邻居加入搜索队列
    searched = []       #这个数组用于记录检查过的人
    while search_queue:
        person = search_queue.popleft()     #队列左侧第一个并删除
        if not person in searched:      #仅当这个人没检查过才检查
            if person_is_seller(person):
                print(person + " is a mango seller!")
                return True
            else:
                search_queue += graph[person]
                searched.append(person)
    return False
```
***
#### 狄克斯特拉算法
迪杰斯特拉算法是由荷兰计算机科学家狄克斯特拉于1959 年提出的，因此又叫狄克斯特拉算法。是从一个顶点到其余各顶点的最短路径算法，解决的是有向图中最短路径问题。迪杰斯特拉算法主要特点是以起始点为中心向外层层扩展，直到扩展到终点为止。  
![图片加载失败](https://github.com/YZJss/note/blob/master/img/01.png)  
每个数字表示的都是时间，单位分钟。为找出从起始到终点耗时最短的路径，你将使用狄克斯特拉算法。  
狄克斯特拉算法包含4个步骤。  
1.找出最便宜的节点，即可在最短时间内前往的节点。  
2.对于该节点的所有邻居，检查是否有前往它们的更短路径，如果有，就更新其开销。  
3.重复以上过程，直到对图中的每个节点都这样做了。  
4.计算出最终路径。  

首先，需要一个散列表来同时存储邻居和前往邻居的开销 
```
graph = {}
graph["start"] = {}
graph["start"]["a"] = 6
graph["start"]["b"] = 2

graph["a"] = {}
graph["a"]["fin"] = 1

graph["b"] = {}
graph["b"]["a"] = 3graph
graph["b"]["fin"] = 5

graph["fin"] = {}
```

接下来，需要用一个散列表来存储每个节点的开销。  
节点的**开销**指的是从起点出发前往该节点需要多长时间。
```
infinity = float("inf")     #无穷大
costs = {}
costs["a"] = 6
costs["b"] = 2
costs["fin"] = infinity
```

还需要一个存储父节点的散列表：
```
parents = {}
parents["a"] = "start"
parents["b"] = "start"
parents["fin"] = None
```
最后，还需要一个数组，用于记录处理过的节点，因为对于同一个节点，不用处理多次。
```
processed = []
```
![图片加载失败](https://github.com/YZJss/note/blob/master/img/02.jpg)  

```
node = find_lowest_cost_node(costs)     #在未处理的节点找出开销最小的节点
while node is not None:
    cost = costs[node]
    neighbors = graph[node]
    for n in neighbors.keys():
        new_cost = cost + neighbors[n]
        if costs[n] > new_code:
        costs[n] = new_cost
        parents[n] = node
    processed.append(node)
    node = find_lowest_cost_node(costs)
```

```
def find_lowest_cost_node(costs):
    lowest_cost = float("inf")
    lowest_cost_node = None
    for node in costs:      #遍历所有节点
        cost = costs[node]
        if cost < lowest_cost and node not in proccessed:       #如果当前节点的开销更低且未处理过
            lowest_cost = cost      #就将其视为开销最低的节点
            lowest_cost_node = node
    return lowest_cost_node
```
#### 小结
* 广度优先搜索用于在非加权图中查找最短路径。
* 狄克斯特拉算法用于在加权图中查找最短路径。
* 仅当权重为正时狄克斯特拉算法才管用。
* 如果图中包含负权边，请使用贝尔曼-福德算法。
***
