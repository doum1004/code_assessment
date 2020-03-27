from typing import List

"""
https://leetcode.com/problems/angle-between-hands-of-a-clock/
"""

class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        minAngle = minutes*6
        hourAngle = hour*30+minutes/2
        result = abs(minAngle - hourAngle)
        return 360 - result if result > 180 else result
        