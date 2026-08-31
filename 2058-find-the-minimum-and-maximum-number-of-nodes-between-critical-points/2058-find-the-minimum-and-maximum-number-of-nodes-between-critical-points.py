from typing import Optional, List

class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional['ListNode']) -> List[int]:
        if not head or not head.next or not head.next.next:
            return [-1, -1]

        first_cp = -1
        last_cp = -1
        min_dist = float('inf')
        
        idx = 1
        prev = head
        curr = head.next
        
        while curr.next:
            if (prev.val < curr.val > curr.next.val) or (prev.val > curr.val < curr.next.val):
                if first_cp == -1:
                    first_cp = idx
                else:
                    min_dist = min(min_dist, idx - last_cp)
                last_cp = idx
            
            prev = curr
            curr = curr.next
            idx += 1
            
        if first_cp == last_cp:
            return [-1, -1]
            
        return [min_dist, last_cp - first_cp]