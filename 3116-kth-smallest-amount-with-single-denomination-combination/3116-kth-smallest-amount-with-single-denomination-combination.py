import math
from typing import List

class Solution:
    def findKthSmallest(self, coins: List[int], k: int) -> int:
        n = len(coins)
        subsets = []
        
        for i in range(1, 1 << n):
            current_lcm = 1
            set_bits = 0
            for j in range(n):
                if (i >> j) & 1:
                    set_bits += 1
                    current_lcm = math.lcm(current_lcm, coins[j])
            subsets.append((current_lcm, set_bits))
            
        def count(x):
            res = 0
            for lcm_val, bits in subsets:
                if bits % 2 == 1:
                    res += x // lcm_val
                else:
                    res -= x // lcm_val
            return res

        low = 1
        high = min(coins) * k
        
        while low < high:
            mid = (low + high) // 2
            if count(mid) >= k:
                high = mid
            else:
                low = mid + 1
                
        return low