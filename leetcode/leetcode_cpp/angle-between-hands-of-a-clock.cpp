#include <iostream>
#include <vector>
#include <cassert>
#include <math.h>

using namespace std;

/**
https://leetcode.com/problems/angle-between-hands-of-a-clock/

- Solution1. Get angle of min,hour and subtract 
- time: o(1)
- space: o(1)

1. get min angle: min*6.0
2. get h angle: h*30.0+(m/2.0)
3. subtract of two anble and get absolute. and if it is larger than 180 return 360-result else result

*/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minAngle = minutes * 6.0;
        double hourAngle = hour * 30.0 + minutes / 2.0;
        double result = fabs(minAngle-hourAngle);
        return result > 180 ? 360 - result : result;
    }
};

int main()
{
    assert(Solution().angleClock(12, 30) == 165);
    assert(Solution().angleClock(3, 30) == 75);
    assert(Solution().angleClock(3, 15) == 7.5);
    assert(Solution().angleClock(4, 50) == 155);

    return 0;
}