class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return 0
        
        z = nums.index(0)
        
        is_fwd = True
        for i in range(1, n):
            if nums[(z + i) % n] != i:
                is_fwd = False
                break
                
        is_bwd = True
        for i in range(1, n):
            if nums[(z - i + n) % n] != i:
                is_bwd = False
                break
                
        if not is_fwd and not is_bwd:
            return -1
            
        if is_fwd:
            return min(z, n - z + 2)
        else:
            return min(z + 2, n - z)