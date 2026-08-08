class Solution:
    def validSequence(self, word1: str, word2: str) -> list[int]:
        n = len(word1)
        m = len(word2)
        
        suf = [-1] * (m + 1)
        suf[m] = n
        
        j = n - 1
        for i in range(m - 1, -1, -1):
            while j >= 0 and word1[j] != word2[i]:
                j -= 1
            if j >= 0:
                suf[i] = j
                j -= 1
            else:
                suf[i] = -1
                
        ans = []
        changed = False
        j = 0
        
        for i in range(m):
            matched = False
            while j < n:
                if word1[j] == word2[i]:
                    ans.append(j)
                    j += 1
                    matched = True
                    break
                elif not changed and suf[i + 1] >= j + 1:
                    ans.append(j)
                    changed = True
                    j += 1
                    matched = True
                    break
                else:
                    j += 1
            
            if not matched:
                return []
                
        return ans