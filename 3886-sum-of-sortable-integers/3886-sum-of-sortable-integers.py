import math

class Solution:
    def sortableIntegers(self, nums: list[int]) -> int:
        n = len(nums)
        pref = [0] * n
        for i in range(n - 1):
            pref[i+1] = pref[i] + (1 if nums[i] > nums[i+1] else 0)
            
        ans = 0
        divs = []
        for k in range(1, int(math.isqrt(n)) + 1):
            if n % k == 0:
                divs.append(k)
                if k * k != n:
                    divs.append(n // k)
                    
        for k in divs:
            prev_max = -float('inf')
            possible = True
            for i in range(0, n, k):
                sub = nums[i:i+k]
                block_min = min(sub)
                if block_min < prev_max:
                    possible = False
                    break
                prev_max = max(sub)
                
                drops = pref[i+k-1] - pref[i] + (1 if nums[i+k-1] > nums[i] else 0)
                if drops > 1:
                    possible = False
                    break
            
            if possible:
                ans += k
                
        return ans