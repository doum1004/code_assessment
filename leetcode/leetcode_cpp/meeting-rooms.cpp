#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/**
https://leetcode.com/problems/meeting-rooms/

Solution1. order(x,y) and check next one
//time: o(nlogn + n)
//space: 1
for true
0 1, 1 3, 5 7

for false
0 2, 1 3
0 5, 1,1

19 20, 1 10, 5 14
1 10, 5 14, 19 20

13 15, 1 13
1 13 13 15
*/

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        for (int i=0; i<(int)intervals.size()-1; ++i) {
            if (intervals[i][1] > intervals[i+1][0])
                return false;
        }
        return true;
    }
};

int main()
{
    auto input1 = vector<vector<int>> {{0,30},{5,10},{15,20}};
    assert(Solution().canAttendMeetings(input1) == (false));
    auto input2 = vector<vector<int>> {{7,10},{2,4}};
    assert(Solution().canAttendMeetings(input2) == (true));
    auto input3 = vector<vector<int>> {{5,8},{6,8}};
    assert(Solution().canAttendMeetings(input3) == (false));

    return 0;
}