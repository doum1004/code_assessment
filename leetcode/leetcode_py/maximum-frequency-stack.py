
from typing import List
import collections

"""
https://leetcode.com/problems/maximum-frequency-stack/

1) push(5)
5: 1
--
1: 5
maxFreq = 1

2) push(7)
5: 1
7: 1
--
1: 5, 7
maxFreq = 1

3) push(5)
5: 2
7: 1
--
1: 5,7
2: 5
maxFreq = 2

"""

class FreqStack:

    def __init__(self):
        self.counter = collections.Counter() #{}
        self.freq = collections.defaultdict(list) #{}
        self.maxFreq = 0

    def push(self, x: int) -> None:
        self.counter[x] += 1
        c = self.counter[x]
        self.freq[c].append(x)
        self.maxFreq = max(c, self.maxFreq)

    def pop(self) -> int:
        x = self.freq[self.maxFreq].pop()
        self.counter[x] -= 1
        if not self.freq[self.maxFreq]:
            self.maxFreq -= 1
        return x
    


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(x)
# param_2 = obj.pop()