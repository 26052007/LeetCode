from typing import List

class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        min_idx = nums.index(min(nums))
        max_idx = nums.index(max(nums))
        
        i = min(min_idx, max_idx)
        j = max(min_idx, max_idx)
        n = len(nums)
        
        return min(j + 1, n - i, i + 1 + n - j)