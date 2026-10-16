class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        sum1 = [0] * (4 * n)
        sum2 = [0] * (4 * n)
        lazy = [0] * (4 * n)
        
        def push_down(node, l, r):
            if lazy[node]:
                v = lazy[node]
                lazy[node] = 0
                mid = (l + r) // 2
                
                len_left = mid - l + 1
                sum2[node * 2] = (sum2[node * 2] + 2 * v * sum1[node * 2] + len_left * v * v) % MOD
                sum1[node * 2] = (sum1[node * 2] + len_left * v) % MOD
                lazy[node * 2] = (lazy[node * 2] + v) % MOD
                
                len_right = r - mid
                sum2[node * 2 + 1] = (sum2[node * 2 + 1] + 2 * v * sum1[node * 2 + 1] + len_right * v * v) % MOD
                sum1[node * 2 + 1] = (sum1[node * 2 + 1] + len_right * v) % MOD
                lazy[node * 2 + 1] = (lazy[node * 2 + 1] + v) % MOD

        def update(node, l, r, ql, qr):
            if ql <= l and r <= qr:
                length = r - l + 1
                sum2[node] = (sum2[node] + 2 * sum1[node] + length) % MOD
                sum1[node] = (sum1[node] + length) % MOD
                lazy[node] = (lazy[node] + 1) % MOD
                return
            
            push_down(node, l, r)
            mid = (l + r) // 2
            if ql <= mid:
                update(node * 2, l, mid, ql, qr)
            if qr > mid:
                update(node * 2 + 1, mid + 1, r, ql, qr)
            
            sum1[node] = (sum1[node * 2] + sum1[node * 2 + 1]) % MOD
            sum2[node] = (sum2[node * 2] + sum2[node * 2 + 1]) % MOD

        last_pos = {}
        ans = 0
        
        for i, x in enumerate(nums):
            start = last_pos.get(x, -1) + 1
            update(1, 0, n - 1, start, i)
            last_pos[x] = i
            ans = (ans + sum2[1]) % MOD
            
        return ans