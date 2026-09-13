import bisect
from typing import List

class Solution:
    def maximumWeight(self, intervals: List[List[int]]) -> List[int]:
        n = len(intervals)
        arr = []
        for i in range(n):
            arr.append((intervals[i][0], intervals[i][1], intervals[i][2], i))
            
        arr.sort(key=lambda x: x[1])
        r_list = [x[1] for x in arr]
        
        dp = [[(-1, []) for _ in range(5)] for _ in range(n + 1)]
        for i in range(n + 1):
            dp[i][0] = (0, [])
            
        for i in range(1, n + 1):
            l, r, w, orig_idx = arr[i - 1]
            p = bisect.bisect_left(r_list, l)
            
            for c in range(1, 5):
                w1, seq1 = dp[i - 1][c]
                
                w2_prev, seq2_prev = dp[p][c - 1]
                if w2_prev != -1:
                    w2 = w2_prev + w
                    seq2 = sorted(seq2_prev + [orig_idx])
                else:
                    w2 = -1
                    seq2 = []
                    
                if w2 > w1:
                    dp[i][c] = (w2, seq2)
                elif w2 == w1 and w1 != -1:
                    if seq2 < seq1:
                        dp[i][c] = (w2, seq2)
                    else:
                        dp[i][c] = (w1, seq1)
                else:
                    dp[i][c] = (w1, seq1)
                    
        best_w = -1
        best_seq = []
        for c in range(1, 5):
            w, seq = dp[n][c]
            if w > best_w:
                best_w = w
                best_seq = seq
            elif w == best_w and w != -1:
                if seq < best_seq:
                    best_seq = seq
                    
        return best_seq