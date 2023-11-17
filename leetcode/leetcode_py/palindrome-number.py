'''
https://leetcode.com/problems/palindrome-number
'''

class Solution:
    def isPalindrome(self, x: int) -> bool:
        x_r = 0
        t = x
        while x>0:
            x_r = x_r * 10 + x % 10
            x //= 10

        return x_r == t