#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>

using namespace std;

/**
https://leetcode.com/problems/happy-number/

// Solution1. find cycle with set
// time: o(logn). o(243*3+logn+loglogn+... processing each digit in the number, and the number of digits in a number is given by logn.
// space: o(n) cycle

// Solution2. find cycle with two pointers(slow,fast)
// time: o(logn)
// space: o(1)

*/

class Solution {
public:
    int nextNum(int n) {
        int sum = 0;
        while (n) {
            auto digit = n % 10;
            n /= 10;
            sum += digit * digit;
        }
        return sum;
    }
    
    bool isHappy_set(int n) {
        unordered_set<int> m;
        int sum=0;
        while (true) {
            sum = nextNum(n);
            
            if (m.count(sum)) return false;
            if (sum == 1) return true;
            
            n = sum;
            m.insert(sum);
        }
        
        return false;
    }
    
    bool isHappy_twopointers(int n) {
        if (n == 1) return true;
        
        int slow = n, fast = n;
        bool flag = false;
        while (true) {
            fast = nextNum(fast);
            if (flag) slow = nextNum(slow);
            flag = !flag;
            
            if (slow == fast) return false;
            if (slow == 1 || fast == 1) return true;
        }
        
        return false;
    }
    
    bool isHappy(int n) {
        //return isHappy_set(n);
        return isHappy_twopointers(n);
    }
};

int main()
{
    assert(Solution().isHappy(19) == (true));
    assert(Solution().isHappy(2) == (false));

    return 0;
}
