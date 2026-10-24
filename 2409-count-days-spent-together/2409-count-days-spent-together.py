class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        days_in_month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        
        def to_days(date_str):
            m, d = int(date_str[:2]), int(date_str[3:])
            return sum(days_in_month[:m-1]) + d
            
        arrive = max(arriveAlice, arriveBob)
        leave = min(leaveAlice, leaveBob)
        
        if arrive > leave:
            return 0
            
        return to_days(leave) - to_days(arrive) + 1