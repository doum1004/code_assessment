#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/**
https://leetcode.com/problems/plus-one/

- Solution1: in place modification
- time: o(n)
- space: o(1)

*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
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
};

int main()
{
    auto input1 = vector<int>{1,2,3};
    assert(Solution().plusOne(input1) == (vector<int>{1,2,4}));

    auto input2 = vector<int>{9,9,9};
    assert(Solution().plusOne(input2) == (vector<int>{1,0,0,0}));

    return 0;
}