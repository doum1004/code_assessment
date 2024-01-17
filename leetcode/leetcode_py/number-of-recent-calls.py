'''
https://leetcode.com/problems/number-of-recent-calls

1. Queue and pop out of range
time: o(n)
space: o(n)
'''
class RecentCounter:

    def __init__(self):
        self.q = []

    def ping(self, t: int) -> int:
        self.q.append(t)
        while self.q[0] < t - 3000:
            self.q.pop(0)
        return len(self.q)

# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t) 