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

1. brute force
time: o(n^2)
space: o(1) without output

2. array of left product and right product
time: o(n)
space: o(n)
   1  2  3  4
lp 1  1  2  6
rp 24 12 4  1

3. use answer array as lp. And get rp in constant value. and update answer
time: o(n)
space: o(1) without output
    1  2  3  4
res 1  1  2  6  (lp)
              
res 1  1  2  6 i = 3, rp = 1
res 1  1  8  6 i = 2, rp = 4
res 1  12  8  6 i = 1, rp = 12
res 24  12  8  6 i = 0, rp = 24

*/

class Solution {
public:
    vector<int> productExceptSelf_1(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        for (int i=0; i<nums.size(); ++i) {
            for (int j=0; j<nums.size(); ++j) {
                if (j == i) continue;
                res[i] *= nums[j];
            }
        }
        return res;
    }
    vector<int> productExceptSelf_2(vector<int>& nums) {
        vector<int> lp(nums.size(), 1);
        for (int i=1; i<nums.size(); ++i) lp[i] = lp[i-1] * nums[i-1];
        vector<int> rp(nums.size(), 1);
        for (int i=nums.size()-2; i>=0; --i) rp[i] = rp[i+1] * nums[i+1];
        for (int i=0; i<nums.size(); ++i) nums[i] = lp[i] * rp[i];
        return nums;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        for (int i=1; i<nums.size(); ++i) {
            res[i] = res[i-1] * nums[i-1];
        }
        
        int rp = 1;
        for (int i=nums.size()-2; i>=0; --i) {
            rp *= nums[i+1];
            res[i] *= rp;
        }
        return res;
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
