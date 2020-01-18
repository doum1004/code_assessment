#include <iostream>
#include <vector>
#include <cassert>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        
        auto maxProfit = 0, minPrice = prices[0];
        for (int i=1; i<prices.size(); ++i) {
            if (minPrice > prices[i]) minPrice = prices[i];
            else maxProfit = max(maxProfit, prices[i] - minPrice);
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