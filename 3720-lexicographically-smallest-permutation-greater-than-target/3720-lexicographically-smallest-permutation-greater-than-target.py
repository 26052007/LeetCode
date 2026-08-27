class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        freq = [0] * 26
        for char in s:
            freq[ord(char) - 97] += 1
        
        last_valid_i = -1
        for i, char in enumerate(target):
            char_idx = ord(char) - 97
            
            for j in range(char_idx + 1, 26):
                if freq[j] > 0:
                    last_valid_i = i
                    break
            
            if freq[char_idx] > 0:
                freq[char_idx] -= 1
            else:
                break
                
        if last_valid_i == -1:
            return ""
            
        freq = [0] * 26
        for char in s:
            freq[ord(char) - 97] += 1
            
        for i in range(last_valid_i):
            freq[ord(target[i]) - 97] -= 1
            
        target_idx = ord(target[last_valid_i]) - 97
        best_c = ""
        for j in range(target_idx + 1, 26):
            if freq[j] > 0:
                best_c = chr(j + 97)
                freq[j] -= 1
                break
                
        suffix = []
        for j in range(26):
            if freq[j] > 0:
                suffix.append(chr(j + 97) * freq[j])
                
        return target[:last_valid_i] + best_c + "".join(suffix)