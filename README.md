https://leetcode.com/study-plan/algorithm/?progress=xows97ec

Algorithm 🧮

### Day 1 Binary Search
```python
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l = 0
        h = len(nums)-1
        while(l<=h):
            m = (h+l)//2
            if(nums[m] == target):
                return m
            elif (nums[m]<target):
                l = m+1
            else:
                h = m-1
            #to find the index where to insert elements
            if(l>h and target > nums[m]):
                m += 1
        return m
```

### Day 2 Two Pointers
```python
# class Solution:
#     def rotate(self, nums: List[int], k: int) -> List[int]:
#         """
#         Do not return anything, modify nums in-place instead.
#         """
#         nl=[]
#         nl=list(reversed(nums[k:]))+nums[0:k-1]
#         return(nl)
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        nums.reverse()
        for i in range(k):
            nums.append(nums[i])
        nums[:] = nums[k:]
        nums.reverse()
```

### Day 3
```python


```
