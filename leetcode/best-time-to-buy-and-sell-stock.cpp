#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// one path linear
// time: o(n)
// space: o(1)

// minPrice = prices[0]
// maxProfit = 0
// 7,1,5,3,6,4
//   i          maxProfit=0 minPrice=1
//     i        maxProfit=4 minPrice=1
//      ...i    maxProfit=5 minPrice=1



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        
        int minPrice = prices[0];
        int maxProfit = 0;
        for (int i=1; i<prices.size(); ++i) {
            maxProfit = max(maxProfit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        
        return maxProfit;
    }
};

int main()
{
    auto input1_1 = vector<int> {7,1,5,3,6,4};
    assert(Solution().maxProfit(
        input1_1
    ) == (5));
    auto input2_1 = vector<int> {7,6,4,3,1};
    assert(Solution().maxProfit(
        input2_1
    ) == (0));
    return 0;
}