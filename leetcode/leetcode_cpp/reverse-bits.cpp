/*

Solution1. int to str bit. and to int again

1. int to str
% 2 and /= 2 -> reversed
ex) 12 (1100)
12 0
6 00
3 001
1 0011

2. add '0' to make 32 size

3. str to int
num[i] * pow(2, n - 1 -i)

Solution2. Bit operation


*/

class Solution {
public:
    uint32_t reverseBits_1(uint32_t n) {
        string s;
        while (n > 0) {
            s += (n % 2) + '0';
            n /= 2;
        }
        while (32 - s.size() > 0) {
            s += '0';
        }
        
        uint32_t r_n = 0;
        for (int i=0; i<s.size(); ++i) {
            r_n += (s[i] - '0') * pow(2, s.size() - 1 - i);
        }
        return r_n;
    }

    uint32_t reverseBits_2(uint32_t n) {
        uint32_t res = 0;
        for (int i=0;i<32;++i) {
            res <<= 1;
            res += n%2;
            n >>= 1;
        }
        return res;
    }

    uint32_t reverseBits(uint32_t n) {
        return reverseBits_2(n);
    }
};