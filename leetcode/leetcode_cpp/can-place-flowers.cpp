/*
https://leetcode.com/problems/can-place-flowers

Solution. Iterate and check condition
time: o(n)
space: o(1)
*/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        for (int i=1; i<flowerbed.size()-1; ++i) {
            if (flowerbed[i] + flowerbed[i-1] + flowerbed[i+1] == 0) {
                n -= 1;
                if (n == 0) return true;
                i += 1;
            }
        }
        return false;
    }
};