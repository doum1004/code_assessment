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
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy_hash(int n) {
        unordered_set<int> s;
        while (n != 1) {
            if (s.count(n)) return false;
            s.insert(n);
            n = nextNum(n);
        }
        
        return true;
    }
    
    bool isHappy_fastslow(int n) {
        bool flag = false;
        int slow = n, fast = n;
        while (fast != 1) {
            fast = nextNum(fast);
            if (flag) slow = nextNum(slow);
            if (slow == fast) return false;
            flag = !flag;
        }
        
        return true;
    }
    
    bool isHappy(int n) {
        //return isHappy_hash(n);
        return isHappy_fastslow(n);
    }
};

int main()
{
    assert(Solution().isHappy(19) == (true));
    assert(Solution().isHappy(2) == (false));

    return 0;
}
