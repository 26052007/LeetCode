from collections import Counter

class Solution:
    def lexPalindromicPermutation(self, s: str, target: str) -> str:
        n = len(s)
        counts = Counter(s)
        
        odd_chars = [ch for ch, freq in counts.items() if freq % 2 != 0]
        if len(odd_chars) > 1:
            return ""
        
        mid = odd_chars[0] if odd_chars else ""
        
        M_counts = {chr(i): 0 for i in range(97, 123)}
        for ch, freq in counts.items():
            M_counts[ch] = freq // 2
            
        m = n // 2
        T_L = target[:m]
        
        if n % 2 == 0:
            T_mid = ""
            T_R = target[m:]
        else:
            T_mid = target[m]
            T_R = target[m+1:]
            
        curr_counts = M_counts.copy()
        fail_idx = 0
        while fail_idx < m and curr_counts[T_L[fail_idx]] > 0:
            curr_counts[T_L[fail_idx]] -= 1
            fail_idx += 1
            
        if fail_idx == m:
            if mid + T_L[::-1] > T_mid + T_R:
                return T_L + mid + T_L[::-1]
        
        i = fail_idx
        if i == m:
            i = m - 1
            if i >= 0:
                curr_counts[T_L[i]] += 1
            
        while i >= 0:
            found_c = None
            for char_code in range(ord(T_L[i]) + 1, 123):
                c = chr(char_code)
                if curr_counts[c] > 0:
                    found_c = c
                    break
                    
            if found_c:
                curr_counts[found_c] -= 1
                ans_L = T_L[:i] + found_c
                rem_chars = []
                for char_code in range(97, 123):
                    c = chr(char_code)
                    rem_chars.append(c * curr_counts[c])
                ans_L += "".join(rem_chars)
                return ans_L + mid + ans_L[::-1]
                
            i -= 1
            if i >= 0:
                curr_counts[T_L[i]] += 1
                
        return ""