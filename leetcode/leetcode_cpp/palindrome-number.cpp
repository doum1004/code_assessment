/*
https://leetcode.com/problems/palindrome-number

Solution1. str and twopointers
time: o(n)
space: o(n)

Solution2. reverse number
time: o(n)
space: o(1)

Solution3. reverse half number
time: o(n)
space: o(1)

*/

class Solution {
public:
    bool isPalindrome_1(int x) {
        if (x < 0) return false;
        string s;
        while (x > 0) {
            s += x % 10;
            x /= 10;
        }
        
        int i=0;
        int j=s.size()-1;
        while (i<j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    bool isPalindrome_2(int x) {
        long r_x = 0;
        long t = x;
        while (x > 0) {
            r_x = r_x * 10 + x % 10;
            x /= 10;
        }
        return r_x == t;
    }
    bool isPalindrome_3(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }

        int r_x = 0;
        while (x > r_x) {
            r_x = r_x * 10 + x % 10;
            x /= 10;
        }
        return x == r_x || x == r_x / 10;
    }
    
    bool isPalindrome(int x) {
        return isPalindrome_3(x);
    }
};