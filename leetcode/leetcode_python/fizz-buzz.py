"""
https://leetcode.com/problems/fizz-buzz/
"""

class Solution:
    def fizzBuzz_solution1(self, n: int) -> List[str]:
        res = []
        for i in range(1, n+1):
            s = ''
            if i % 3 == 0:
                s += 'Fizz'
            if i % 5 == 0:
                s += 'Buzz'
            if not s:
                s = str(i)
            res.append(s)
        return res
    
    def fizzBuzz_solution2(self, n: int) -> List[str]:
        fb_dict = {3: 'Fizz', 5: 'Buzz'}
        res = []
        for i in range(1, n+1):
            s = ''
            for k in fb_dict.keys():
                if i % k == 0:
                    s += fb_dict[k]
            if not s:
                s = str(i)
            res.append(s)
        return res
        
    def fizzBuzz(self, n: int) -> List[str]:
        #return self.fizzBuzz_solution1(n)
        return self.fizzBuzz_solution2(n)
        