from collections import deque

class Solution:
    def countNonDecreasingSubarrays(self, nums: List[int], k: int) -> int:
        q = deque()
        cost = 0
        r = len(nums) - 1
        ans = 0

        for i in range(len(nums) - 1, -1, -1):
            x = nums[i]
            cnt = 1

            while q and q[-1][0] <= x:
                val, c = q.pop()
                cost += (x - val) * c
                cnt += c

            q.append([x, cnt])

            while cost > k:
                val = q[0][0]
                cost -= val - nums[r]

                q[0][1] -= 1

                if q[0][1] == 0:
                    q.popleft()

                r -= 1

            ans += r - i + 1

        return ans