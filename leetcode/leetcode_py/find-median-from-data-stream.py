'''
https://leetcode.com/problems/find-median-from-data-stream

Solution1 simple sort at findMedian
time: o(nlogn). add: o(1). median: sort o(nlogn)
space: o(n) vector

Solution2 insertion sort
time: o(n). add: bin search(logn) insertion(n). median: o(1)
space: o(n)
auto it = lower_bound(v.begin(), v.end(), num);
v.insert(it, num)

Solution3 heaps. min-heap, max-heap
time: o(logn) heap delete/insert logn
'''
class MedianFinder_1:

    def __init__(self):
        self.nums = []        

    def addNum(self, num: int) -> None:
        self.nums.append(num)
        
    def findMedian(self) -> float:
        self.nums.sort()
        n = len(self.nums)
        return self.nums[n // 2] if n % 2 == 1 else (self.nums[n//2-1] + self.nums[n//2]) / 2
        
class MedianFinder:

    def __init__(self):
        self.lo = []
        self.hi = []   

    def addNum(self, num: int) -> None:
        heappush(self.lo, -num)
        heappush(self.hi, -self.lo[0])
        heappop(self.lo)

        if len(self.lo) < len(self.hi):
            heappush(self.lo, -self.hi[0])
            heappop(self.hi)
            
    def findMedian(self) -> float:
        if len(self.lo) == len(self.hi):
            return (self.hi[0] - self.lo[0]) / 2
        return -self.lo[0]


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()