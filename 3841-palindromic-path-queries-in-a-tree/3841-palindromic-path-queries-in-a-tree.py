class Solution:
    def palindromePath(self, n: int, edges: list[list[int]], s: str, queries: list[str]) -> list[bool]:
        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
            
        tin = [0] * n
        tout = [0] * n
        depth = [0] * n
        LOG = 20
        up = [[0] * LOG for _ in range(n)]
        
        timer = 0
        stack = [(0, 0, 0, False)]
        
        while stack:
            u, p, d, is_post = stack.pop()
            if not is_post:
                timer += 1
                tin[u] = timer
                depth[u] = d
                up[u][0] = p
                for i in range(1, LOG):
                    up[u][i] = up[up[u][i-1]][i-1]
                
                stack.append((u, p, d, True))
                for v in adj[u]:
                    if v != p:
                        stack.append((v, u, d + 1, False))
            else:
                tout[u] = timer
                
        bit = [0] * (n + 2)
        
        def update(idx, val):
            while idx <= n:
                bit[idx] ^= val
                idx += idx & -idx
                
        def range_update(l, r, val):
            update(l, val)
            update(r + 1, val)
            
        def bit_query(idx):
            res = 0
            while idx > 0:
                res ^= bit[idx]
                idx -= idx & -idx
            return res
            
        def get_lca(u, v):
            if depth[u] < depth[v]:
                u, v = v, u
            diff = depth[u] - depth[v]
            for i in range(LOG):
                if (diff >> i) & 1:
                    u = up[u][i]
            if u == v:
                return u
            for i in range(LOG - 1, -1, -1):
                if up[u][i] != up[v][i]:
                    u = up[u][i]
                    v = up[v][i]
            return up[u][0]
            
        chars = [0] * n
        for i in range(n):
            chars[i] = 1 << (ord(s[i]) - ord('a'))
            range_update(tin[i], tout[i], chars[i])
            
        ans = []
        for q in queries:
            parts = q.split()
            if parts[0] == "update":
                u = int(parts[1])
                c = parts[2]
                new_val = 1 << (ord(c) - ord('a'))
                diff = chars[u] ^ new_val
                range_update(tin[u], tout[u], diff)
                chars[u] = new_val
            else:
                u = int(parts[1])
                v = int(parts[2])
                lca = get_lca(u, v)
                mask = bit_query(tin[u]) ^ bit_query(tin[v]) ^ chars[lca]
                ans.append((mask & (mask - 1)) == 0)
                
        return ans