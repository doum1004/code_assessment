/*
https://leetcode.com/problems/online-stock-span/

1. Stack with price and days
time: o(n)
space: o(n)
*/

class StockSpanner {
public:
    StockSpanner() {        
    }
    
    int next(int price) {
        int day = 1;
        while (!priceSpans.empty() && priceSpans.back().first <= price) {
            day += priceSpans.back().second;
            priceSpans.pop_back();
        }
        priceSpans.emplace_back(price, day);
        return day;
    }

    vector<pair<int,int>> priceSpans; // n
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */