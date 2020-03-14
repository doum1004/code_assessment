#include <iostream>
#include <cassert>

using namespace std;

/**
https://leetcode.com/problems/count-and-say/

//Solution1. recursion
//time:o(n*k). length of result(k) * n
//space:o(n). recursion

*/

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        else if (n == 2) return "11";
        
        string res;
        
        auto str = countAndSay(n-1);
        char pre = ' ';
        int count = 0;
        for (auto &c:str) {
            if (pre == ' ') {
                count = 1;
            }
            else if (pre == c) {
                count++;
            }
            else {
                res += to_string(count) + pre;
                count = 1;
            }
            pre = c;
        }
        if (pre != ' ') res += to_string(count) + pre;
        
        return res;
    }
};

int main()
{
    assert(Solution().countAndSay(5) == "111221");
    return 0;
}