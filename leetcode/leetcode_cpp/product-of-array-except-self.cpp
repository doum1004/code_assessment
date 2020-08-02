/*
https://leetcode.com/problems/product-of-array-except-self/

1. Math. Get product of all number and divide its number. (Extra case of zero)
o(n) / o(1)

2. Left Right Products (from solution)
o(n) / o(1)
- Product previous ans and num from left side
- Product nums(previous to last) (right side)

*/

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
