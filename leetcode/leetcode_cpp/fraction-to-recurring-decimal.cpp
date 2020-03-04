#include <iostream>
#include <unordered_map>
#include <cassert>

using namespace std;

/**
https://leetcode.com/problems/fraction-to-recurring-decimal/

// Solution1. Long division
// time: o(n). len(divisor)+1
// space: o(n). len(divisor)

1. if no reminder after division, return division result.
2. if there is reminder, get reminder till repeating
2.1 get reminder of a left most digit
2.1.1 r = n. r %= d. r *= 10. result = r/d
2.2 and store it in map, to track repeating
2.3 r %= d is 0 or in case of 'r' repeating in map than, exit

*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        if (denominator == 0) throw invalid_argument("wrong input of denominator");
        
        string res;
        if (numerator < 0 ^ denominator < 0) res += "-";
        
        long long n = labs(numerator);
        long long d = labs(denominator);
        
        res += to_string(n/d);
        long long r = n % d;
        if (r == 0) return res;
        
        res += ".";
        
        unordered_map<int,int> m;
        for (; r; r%=d) {
            cout << r << endl;
            if (m.count(r)) {
                res.insert(m[r], "(");
                res += ")";
                break;
            }
            m[r] = res.size();
            r *= 10;
            res += to_string(r/d);
        }
        
        return res;
    }
};

int main()
{
    assert(Solution().fractionToDecimal(1, 2) == ("0.5"));
    assert(Solution().fractionToDecimal(2, 1) == ("2"));
    assert(Solution().fractionToDecimal(2, 3) == ("0.(6)"));
    assert(Solution().fractionToDecimal(-2, 3) == ("-0.(6)"));
    assert(Solution().fractionToDecimal(-2, -3) == ("0.(6)"));
    assert(Solution().fractionToDecimal(4, 333) == ("0.012"));
    return 0;
}