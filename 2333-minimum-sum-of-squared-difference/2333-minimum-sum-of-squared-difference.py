class Solution:
    def minSumSquareDiff(self, nums1: list[int], nums2: list[int], k1: int, k2: int) -> int:
        k = k1 + k2
        diffs = [abs(a - b) for a, b in zip(nums1, nums2)]
        
        if sum(diffs) <= k:
            return 0
            
        max_diff = max(diffs)
        buckets = [0] * (max_diff + 1)
        for d in diffs:
            buckets[d] += 1
            
        for i in range(max_diff, 0, -1):
            if buckets[i] > 0:
                if k >= buckets[i]:
                    buckets[i - 1] += buckets[i]
                    k -= buckets[i]
                    buckets[i] = 0
                else:
                    buckets[i - 1] += k
                    buckets[i] -= k
                    break
                    
        return sum((i * i) * count for i, count in enumerate(buckets) if count > 0)