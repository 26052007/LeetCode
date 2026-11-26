class Solution:
    def canAliceWin(self, n: int) -> bool:
        need = 10
        turns = 0
        while n >= need:
            n -= need
            need -= 1
            turns += 1
        return turns % 2 == 1