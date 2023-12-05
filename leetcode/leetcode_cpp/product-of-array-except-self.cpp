#include <iostream>
#include <cassert>
#include "../utils.h"

#include <vector>
#include <sstream>

#include <cctype>
#include <stack>

using namespace std;

/*
https://leetcode.com/problems/product-of-array-except-self

// iterate i: 0 to n
// iterate j: 0 to n except (i)

// with division. product all and divide
// 1 2 3 4. all 24
// 24 / 1. 24 / 2 ...
// time: o(n)

// Solution1. store left/right product
// time: o(n) : n + n + n
// space: o(n) : n + n (no for ans)
// 1  2  3 4
// 1  1  2 3 lp
// 24 12 4 1 rp
//
// [1] 2 3 4 sum[0] = lp[0] * rp[0]
// 1 [2] 3 4 sum[1] = lp[1] * rp[2]
// 1 2 [3] 4
// 1 2 3 [4]
// iterate 0 to n-1 to store left side product result
// iterate n-1 to 0 to sotre right side product result

// solution2. combine lp and rp to ans
// time: o(n)
// space: o(1)
// same for lp for ans. and product ans to make it answer from right side.
// r = 1
// i=n-1 to 0
//  ans[i] = ans[i] * r
//  r *= ans[i]
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if (n < 0) return vector<int>();
        
        if (false) {
            // solution1
            vector<int> ans;
            auto lp = new int[n];
            lp[0] = 1;
            for (int i=0; i<n-1; ++i) {
                lp[i+1] = lp[i] * nums[i];
            }

            auto rp = new int[n];
            rp[n-1] = 1;
            for (int i=n-1; i>0; --i) {
                rp[i-1] = rp[i] * nums[i];
            }

            for (int i=0; i<n; ++i) {
                ans.push_back(lp[i] * rp[i]);
            }
            
            return ans;
        }
        else {
            // solution2
            auto ans = vector<int>(n, 0);
            
            ans[0] = 1;
            for (int i=0; i<n-1; ++i) {
                ans[i+1] = ans[i] * nums[i];
            }
            
            int r = 1;
            for (int i=n-1; i>=0; --i) {
                ans[i] = ans[i] * r;
                r *= nums[i];
            }
            
            return ans;
        }
        
        return vector<int>();
    }
};

int main()
{
    auto input1 = vector<int> {1,2,3,4};
    auto expect1 = vector<int> {24,12,8,6};
    assert(Solution().productExceptSelf(input1)
        == (expect1));

    return 0;
}






/*
https://leetcode.com/problems/product-of-array-except-self/

1. Math. Get product of all number and divide its number. (Extra case of zero)
o(n) / o(1)

2. Left Right Products (from solution)
o(n) / o(1)
- Product previous ans and num from left side
- Product nums(previous to last) (right side)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mode = 1;
        if (mode == 0) {
            int n = nums.size();
            vector<int> res(n);

            int product = 1;
            int countZero = 0;
            for (auto num:nums) {
                if (num != 0) product *= num;
                else countZero++;
            }

            for (int i=0; i<n; ++i) {
                auto c = 0;
                if (countZero > 1) c = 0;
                else if (nums[i] == 0) c = product;
                else c = (countZero > 0) ? 0 : product/nums[i];
                res[i] = c;
            }

            return res;
        }
        else {
            int n = nums.size();
            vector<int> res(n);
            res[0] = 1;
            for (int i=1; i<n; ++i) {
                res[i] = res[i-1] * nums[i-1];
            }

            int R = 1;
            for (int j=n-1; j>0; --j) {
                R *= nums[j];
                res[j-1] *= R;
            }

            return res;
        }
    }
};

*/
