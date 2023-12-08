'''
https://leetcode.com/problems/lru-cache

Solution1. Linked list. Relink node on head and tail.
time: get(1) put(1)
space: o(n)
'''
class MyNode:
    def __init__(self, key, value):
        self.key = key
        self.val = value
        self.prev = None
        self.next = None

class LRUCache:
        
    def __init__(self, capacity: int):
        self.n = capacity
        self.m = {}
        self.head = MyNode(0, 0)
        self.tail = self.head

    def get(self, key: int) -> int:
        if self.n == 0 or key not in self.m: return -1
        
        node = self.m[key]
        if node != self.tail:
            pre = node.prev
            next = node.next
            pre.next = next
            if next:
                next.prev = pre
            self.tail.next = node
            node.prev = self.tail 
            self.tail = node
        return node.val
        
        


    def put(self, key: int, value: int) -> None:
        if self.n == 0: return
        
        if key in self.m:
            self.get(key)
            self.m[key].val = value
            return

        if len(self.m) == self.n:
            # erase
            tbd = self.head.next
            if tbd == self.tail:
                self.tail = self.head
            pre = tbd.prev
            next = tbd.next
            pre.next = next
            if next:
                next.prev = pre            
            del self.m[tbd.key]
        
        # add
        self.m[key] = MyNode(key, value)
        self.tail.next = self.m[key]
        self.m[key].prev = self.tail
        self.tail = self.m[key]
        
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)