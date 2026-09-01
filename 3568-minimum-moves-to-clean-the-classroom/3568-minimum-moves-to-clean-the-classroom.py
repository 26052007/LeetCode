from collections import deque
from typing import List

class Solution:
    def minMoves(self, classroom: List[str], energy: int) -> int:
        m, n = len(classroom), len(classroom[0])
        L_idx = {}
        sr = sc = -1
        
        for r in range(m):
            for c in range(n):
                if classroom[r][c] == 'L':
                    L_idx[(r, c)] = len(L_idx)
                elif classroom[r][c] == 'S':
                    sr, sc = r, c
                    
        num_L = len(L_idx)
        target_mask = (1 << num_L) - 1
        
        if target_mask == 0:
            return 0
            
        visited = [[[-1] * (1 << num_L) for _ in range(n)] for _ in range(m)]
        visited[sr][sc][0] = energy
        
        q = deque([(sr, sc, 0, energy, 0)])
        
        while q:
            r, c, mask, e, steps = q.popleft()
            
            if e == 0:
                continue
                
            nxt_steps = steps + 1
            nxt_e_base = e - 1
            
            for nr, nc in ((r+1, c), (r-1, c), (r, c+1), (r, c-1)):
                if 0 <= nr < m and 0 <= nc < n:
                    cell = classroom[nr][nc]
                    if cell == 'X':
                        continue
                        
                    nxt_e = nxt_e_base
                    nxt_mask = mask
                    
                    if cell == 'R':
                        nxt_e = energy
                    elif cell == 'L':
                        nxt_mask |= (1 << L_idx[(nr, nc)])
                        
                    if nxt_e > visited[nr][nc][nxt_mask]:
                        visited[nr][nc][nxt_mask] = nxt_e
                        if nxt_mask == target_mask:
                            return nxt_steps
                        q.append((nr, nc, nxt_mask, nxt_e, nxt_steps))
                        
        return -1