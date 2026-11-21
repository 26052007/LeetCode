from typing import List


class Solution:
    def findSubtreeSizes(self, parent: List[int], s: str) -> List[int]:
        n = len(parent)
        orig_children = [[] for _ in range(n)]
        for i in range(1, n):
            orig_children[parent[i]].append(i)

        new_children = [[] for _ in range(n)]
        last_seen = [-1] * 26

        def dfs_reparent(u: int) -> None:
            c = ord(s[u]) - 97
            anc = last_seen[c]
            if u != 0:
                p = anc if anc != -1 else parent[u]
                new_children[p].append(u)
            prev = last_seen[c]
            last_seen[c] = u
            for v in orig_children[u]:
                dfs_reparent(v)
            last_seen[c] = prev

        dfs_reparent(0)

        ans = [0] * n

        def dfs_size(u: int) -> int:
            total = 1
            for v in new_children[u]:
                total += dfs_size(v)
            ans[u] = total
            return total

        dfs_size(0)
        return ans