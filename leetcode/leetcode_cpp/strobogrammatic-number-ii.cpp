#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>

using namespace std;

/**
https://leetcode.com/problems/strobogrammatic-number-ii/

Solution1. Backtracking
time: o(n^2)
space; o(1)

Time: O(5 ^ (n/2)) ~ O(2^n) - we have 5 choices for every position and we will do this selection n/2 times (because when we append one character, we also append the corresponding matching one)
Space: recursion stack - O(5 ^ (n/2)) ~ O(2^n)

*/

class Solution {
public:
    vector<string> helper(int m, int n) {
        if (m == 0) return vector<string> {""};
        if (m == 1) return vector<string> {"0", "1", "8"};
        vector<string> tmp = helper(m-2, n), res;
        
        for (int i=0; i<tmp.size(); ++i) {
            if (m!=n) res.push_back("0" + tmp[i] + "0");
            res.push_back("1" + tmp[i] + "1");
            res.push_back("6" + tmp[i] + "9");
            res.push_back("8" + tmp[i] + "8");
            res.push_back("9" + tmp[i] + "6");
        }
        return res;
    }
    vector<string> findStrobogrammatic(int n) {
        return helper(n,n);
    }
};

int main()
{
    assert(Solution().findStrobogrammatic(2) == (vector<string> {"11","69","88","96"}));

    return 0;
}
