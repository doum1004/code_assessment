#include <iostream>
#include <cassert>

using namespace std;

/**
https://leetcode.com/problems/student-attendance-record-i/

// Solution1. Flag A and L in interation
// time: o(n)
// space: o(1)

*/

class Solution {
public:
    bool checkRecord(string s) {
        int count_absent = 0;
        int count_late = 0;
        for (auto &c:s) {
            if (tolower(c) == 'l') {
                count_late++;
                if (count_late > 2) return false;
            }
            else {
                count_late = 0;
                if (tolower(c) == 'a') {
                    count_absent++;
                    if (count_absent > 1) return false;
                }
            }
        }
        
        return true;
    }
};

int main()
{
    assert(Solution().checkRecord("PPALLP")
        == true);
    assert(Solution().checkRecord("PPALLL")
        == false);
    return 0;
}