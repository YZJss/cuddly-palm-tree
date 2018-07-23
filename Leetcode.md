# **Leetcode 学习笔记**
## 初级算法
### 数组
* 1.从排序数组中删除重复项
   >给定一个**排序**数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
    不要使用额外的数组空间，你必须在**原地**修改输入数组并在使用O(1)额外空间的条件下完成。
##### 示例:
    ```
    给定数组 nums = [1,1,2], 函数应该返回新的长度 2,
     
    并且原数组 nums 的前两个元素被修改为 1, 2。
     
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
* 2.买卖股票的最佳时机 II
   >给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
    设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
    **注意**：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
##### 示例:
    ```
    输入: [7,1,5,3,6,4]
    输出: 7
    解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
          随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。 
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