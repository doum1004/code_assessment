class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 + str2 != str2 + str1: return ""
        def findGCD(a, b):
            return a if b == 0 else findGCD(b, a%b) # or :math.gcd(a, b)
        return str1[:findGCD(len(str1), len(str2))]