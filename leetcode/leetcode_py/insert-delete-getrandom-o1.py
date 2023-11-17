from typing import List

"""
https://leetcode.com/problems/insert-delete-getrandom-o1/

"""

class RandomizedSet:

    def __init__(self):
        self.list = []
        self.set = {}
        

    def insert(self, val: int) -> bool:
        if val in self.set:
            return False
        self.set[val] = len(self.list)
        self.list.append(val)
        return True
        

    def remove(self, val: int) -> bool:
        if not val in self.set:
            return False
        idx = self.set[val]
        last_val = self.list[-1]
        self.set[last_val] = idx
        self.list[idx] = last_val
        del self.set[val]
        self.list.pop()
        
        return True
        

    def getRandom(self) -> int:
        #return random.choice(self.list)
        return self.list[random.randrange(len(self.list))]
        


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()