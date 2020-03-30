"""
https://leetcode.com/problems/next-closest-time/
"""

class Solution:
    def nextClosestTime_bruteforce(self, time: str) -> str:
        h = {int(x) for x in time if x != ':'}        
        start = int(time[:2]) * 60 + int(time[3:])
        
        while True:
            start = (start + 1) % 1440
            times = [start//60//10, start//60%10, start%60//10, start%60%10]
            
            valid = True
            for n in times:
                if n not in h:
                    valid = False
                    break
            if not valid: continue
                
            break
            
        return str(start//60//10) + str(start//60%10) + ":" + str(start%60//10) + str(start%60%10)
        
    def nextClosestTime(self, time: str) -> str:
        return self.nextClosestTime_bruteforce(time)