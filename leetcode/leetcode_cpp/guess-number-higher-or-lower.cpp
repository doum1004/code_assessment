/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
/*
https://leetcode.com/problems/guess-number-higher-or-lower

1. Binary search
time: o(logn)
space: o(1)
*/
class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l <= r) {
            int m = (r - l) / 2 + l;
            int result = guess(m);
            if (result == 0) return m;
            else if (result == -1) r = m - 1;
            else l = m + 1;
        }
        return -1;
    }
};