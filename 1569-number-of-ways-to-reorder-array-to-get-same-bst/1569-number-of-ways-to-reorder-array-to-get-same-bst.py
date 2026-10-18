import math

class Solution:
    def numOfWays(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        
        def ways(arr):
            if len(arr) <= 2:
                return 1
            
            root = arr[0]
            left = [x for x in arr if x < root]
            right = [x for x in arr if x > root]
            
            combinations = math.comb(len(left) + len(right), len(left))
            
            return (combinations * ways(left) * ways(right)) % MOD
            
        return (ways(nums) - 1) % MOD