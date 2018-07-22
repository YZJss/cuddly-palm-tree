# **Leetcode 学习笔记**
## 初级算法
### 数组
* 1.从排序数组中删除重复项
   >给定一个**排序**数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
    不要使用额外的数组空间，你必须在**原地**修改输入数组并在使用O(1)额外空间的条件下完成。
#### 示例:
    ```
    给定数组 nums = [1,1,2], 函数应该返回新的长度 2,
     
    并且原数组 nums 的前两个元素被修改为 1, 2。
     
    你不需要考虑数组中超出新长度后面的元素。
    ```
#### 代码(python):
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
****
