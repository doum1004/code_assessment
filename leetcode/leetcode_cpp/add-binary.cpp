/*
https://leetcode.com/problems/add-binary

Solution1. iterate and convert to sum
time: o(n)
space: o(n)

1. iterate
2. char to int. sum
3. take care of carrier
4. reverse string

*/

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        
        int i = a.size()-1, j = b.size()-1, sum = 0;
        string res;
        while (i>=0 || j>=0 || sum) {
            if (i>=0) sum += a[i--] - '0';
            if (j>=0) sum += b[j--] - '0';
            res += sum % 2 + '0';
            sum /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    return 0;
}