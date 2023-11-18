#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/**
https://leetcode.com/problems/plus-one/

- Solution1: in place modification Iteration
- time: o(n)
- space: o(1)

*/

class Solution {
public:
    vector<int> plusOne_1(vector<int>& digits) {
        int n = digits.size();
        for (int i=n-1; i>=0; --i) {
            digits[i] += 1;
            if (digits[i] == 10) {
                digits[i] = 0;
            }
            else {
                return digits;
            }
        }
        
        digits.insert(digits.begin(), 1);
        return digits;
    }
    
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if (n == 0) return digits;
        int i = n - 1;
        while (i>=0) {
            digits[i]++;
            if (digits[i] != 10)
                break;
            digits[i] = 0;
            if (i == 0) digits.insert(digits.begin(), 1);
            i--;
        }

        return digits;
    }
};

int main()
{
    auto input1 = vector<int>{1,2,3};
    assert(Solution().plusOne(input1) == (vector<int>{1,2,4}));

    auto input2 = vector<int>{9,9,9};
    assert(Solution().plusOne(input2) == (vector<int>{1,0,0,0}));

    return 0;
}