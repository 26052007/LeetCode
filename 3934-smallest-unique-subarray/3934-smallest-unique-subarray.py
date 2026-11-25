class Solution:
    def smallestUniqueSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        trans = [{}]
        link = [-1]
        length = [0]
        cnt = [0]
        last = 0

        for x in nums:
            cur = len(trans)
            trans.append({})
            link.append(0)
            length.append(length[last] + 1)
            cnt.append(1)

            p = last
            while p != -1 and x not in trans[p]:
                trans[p][x] = cur
                p = link[p]

            if p == -1:
                link[cur] = 0
            else:
                q = trans[p][x]
                if length[p] + 1 == length[q]:
                    link[cur] = q
                else:
                    clone = len(trans)
                    trans.append(trans[q].copy())
                    link.append(link[q])
                    length.append(length[p] + 1)
                    cnt.append(0)
                    while p != -1 and trans[p].get(x) == q:
                        trans[p][x] = clone
                        p = link[p]
                    link[q] = link[cur] = clone
            last = cur

        m = len(trans)
        c = [0] * (n + 1)
        for l in length:
            c[l] += 1
        for i in range(1, n + 1):
            c[i] += c[i - 1]
        order = [0] * m
        for i in range(m - 1, -1, -1):
            l = length[i]
            c[l] -= 1
            order[c[l]] = i

        ans = n
        for i in range(m - 1, 0, -1):
            u = order[i]
            p = link[u]
            cnt[p] += cnt[u]
            if cnt[u] == 1:
                cand = length[p] + 1
                if cand < ans:
                    ans = cand

        return ans