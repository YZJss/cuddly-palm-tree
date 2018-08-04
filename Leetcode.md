# **Leetcode 学习笔记**
## 初级算法
### 数组
___
* 1.从排序数组中删除重复项
   >给定一个**排序**数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
    不要使用额外的数组空间，你必须在**原地**修改输入数组并在使用O(1)额外空间的条件下完成。
##### 示例:
```
给定数组 nums = [1,1,2], 

函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 

你不需要考虑数组中超出新长度后面的元素。
```
##### 代码(python):
```
class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        j = 0
        if len(nums)<=1:
            return len(nums)
        else:
            for i in range(1,len(nums)):
                if nums[j]!=nums[i]:
                    j+=1
                    nums[j]=nums[i]
            return j+1
```
___
* 2.买卖股票的最佳时机 II
   >给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
    设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
    **注意**：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
##### 示例:
```
输入: [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 
```
##### 代码(python):
```
class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        j = 0
        sum =0
        for i in range(1,len(prices)):
            if prices[i] < prices[j]:
                j+=1
                continue
            else:
                sum+=(prices[i]-prices[j])
                j+=1
        return sum
```
___
* 3.旋转数组
   >给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
##### 示例:
```
输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
```   
##### 代码(python):
```
class Solution:
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        l = len(nums)
        nums[:] = nums[l-k:] + nums[:l-k]
```
___
* 4.存在重复
   >给定一个整数数组，判断是否存在重复元素。
    如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
##### 示例:
```
输入: [1,2,3,1]
输出: true
```
##### 代码(python):
```
class Solution:
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        nums.sort()
        for i in range(0, len(nums)-1):
            if nums[i] == nums[i+1]:
                return True
        return False
```
ps: dict.has_key(key) or return len(nums) != len(set(nums)) 这俩种方法也可以
___
* 5.只出现一次的数字
   >给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
###### 说明：你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
##### 示例:
```
输入: [2,2,1]
输出: 1
```
##### 代码(python):
```
#异或运算 a⊕b⊕a=b
class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0
        for i in nums:
            res^=i
        return res
```
方法2: return sum(set(nums))*2-sum(nums) 
___
* 6.两个数组的交集 II
   >给定两个数组，写一个方法来计算它们的交集。
##### 示例:
```
给定 nums1 = [1, 2, 2, 1], nums2 = [2, 2], 返回 [2, 2]
```
注意：
* 输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
* 我们可以不考虑输出结果的顺序。

跟进:
* 如果给定的数组已经排好序呢？你将如何优化你的算法？
* 如果 nums1 的大小比 nums2 小很多，哪种方法更优？
* 如果nums2的元素存储在磁盘上，内存是有限的，你不能一次加载所有的元素到内存中，你该怎么办？

##### 代码(python):
```
class Solution:
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        from collections import Counter
        return list((Counter(nums1) & Counter(nums2)).elements())
```
___