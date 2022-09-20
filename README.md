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


```
