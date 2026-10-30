import heapq
from typing import List

class Solution:
    def shortestPath(self, n: int, edges: List[List[int]], labels: str, k: int) -> int:
        adj = [[] for _ in range(n)]
        for u, v, w in edges:
            adj[u].append((v, w))
            
        dist = {}
        pq = []
        
        initial_streak = 1
        heapq.heappush(pq, (0, 0, initial_streak))
        dist[(0, initial_streak)] = 0
        
        while pq:
            d, u, streak = heapq.heappop(pq)
            
            if u == n - 1:
                return d
                
            if d > dist.get((u, streak), float('inf')):
                continue
                
            for v, w in adj[u]:
                c_u = labels[u]
                c_v = labels[v]
                
                if c_v == c_u:
                    new_streak = streak + 1
                else:
                    new_streak = 1
                    
                if new_streak > k:
                    continue
                    
                nd = d + w
                if nd < dist.get((v, new_streak), float('inf')):
                    dist[(v, new_streak)] = nd
                    heapq.heappush(pq, (nd, v, new_streak))
                    
        return -1