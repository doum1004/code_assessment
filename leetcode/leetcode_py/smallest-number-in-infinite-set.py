'''
https://leetcode.com/problems/smallest-number-in-infinite-set

1. Using set
time: o(logn)
space: o(n)
'''
class SmallestInfiniteSet:

    def __init__(self):
        self.cur = 1
        self.s = set()
        
    def popSmallest(self) -> int:
        if self.s:
            res = min(self.s)
            self.s.remove(res)
            return res
        res, self.cur = self.cur, self.cur+1
        return res

    def addBack(self, num: int) -> None:
        if self.cur <= num:
            return
        self.s.add(num)
        


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)