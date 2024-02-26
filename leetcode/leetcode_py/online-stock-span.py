'''
https://leetcode.com/problems/online-stock-span/

1. Stack with price and days
time: o(n)
space: o(n)
'''
class StockSpanner:

    def __init__(self):
        self.priceDays = []

    def next(self, price: int) -> int:
        day = 1
        while self.priceDays and self.priceDays[-1][0] <= price:
            day += self.priceDays[-1][1]
            self.priceDays.pop()
        self.priceDays.append((price, day))
        return day
        


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)