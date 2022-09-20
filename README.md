https://leetcode.com/study-plan/algorithm/?progress=xows97ec

Algorithm ![image](https://user-images.githubusercontent.com/78896740/191184242-8b625190-ad0f-4f52-a7f8-f45b39ab842c.png){:height="36px" width="36px"}

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
