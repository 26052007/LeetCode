from collections import defaultdict
from typing import List

class Solution:
    def countServers(self, n: int, logs: List[List[int]], x: int, queries: List[int]) -> List[int]:
        logs.sort(key=lambda item: item[1])
        sorted_queries = sorted(enumerate(queries), key=lambda item: item[1])
        
        ans = [0] * len(queries)
        counts = defaultdict(int)
        active_servers = 0
        left = 0
        right = 0
        m = len(logs)
        
        for idx, q in sorted_queries:
            window_start = q - x
            window_end = q
            
            while right < m and logs[right][1] <= window_end:
                server_id = logs[right][0]
                if counts[server_id] == 0:
                    active_servers += 1
                counts[server_id] += 1
                right += 1
                
            while left < m and logs[left][1] < window_start:
                server_id = logs[left][0]
                counts[server_id] -= 1
                if counts[server_id] == 0:
                    active_servers -= 1
                left += 1
                
            ans[idx] = n - active_servers
            
        return ans
        