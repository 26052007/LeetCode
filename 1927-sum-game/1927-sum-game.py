class Solution:
    def sumGame(self, num: str) -> bool:
        n = len(num)
        half = n // 2
        s1 = s2 = q1 = q2 = 0
        
        for i in range(half):
            if num[i] == '?':
                q1 += 1
            else:
                s1 += int(num[i])
                
        for i in range(half, n):
            if num[i] == '?':
                q2 += 1
            else:
                s2 += int(num[i])
                
        if (q1 + q2) % 2 != 0:
            return True
            
        return (s1 - s2) * 2 != (q2 - q1) * 9