#include <iostream>
#include <cassert>

#include <stack>
#include <unordered_set>

using namespace std;

/**
https://leetcode.com/problems/next-closest-time/

- Solution1. Simulation (brute force)
- time: o(1). up to 24*60 1440
- space: o(1)

- Solution2. Build from allowed digits
- time: o(1). up to 4^4
- space: o(1)

*/

class Solution {
public:    
    string nextClosestTime_bruteforce(string& time) {
        unordered_set<int> h;
        for (auto &c:time) if (c != ':' && !h.count(c - '0')) h.insert(c - '0');
        
        int start = stoi(time.substr(0,2)) * 60 + stoi(time.substr(3));
        while (true) {
            start++;
            auto cur = start % 1440;
            int times[4] = {cur/60/10,cur/60%10,cur%60/10,cur%60%10};
            bool valid = true;
            for (int i=0; i<4; ++i) {
                if (!h.count(times[i])) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) break;
        }
        start %= 1440;
        
        return to_string(start/60/10) + to_string(start/60%10) + ":" + to_string(start%60/10) + to_string(start%60%10);
    }
    
    string nextClosestTime_allowed(string& time) {
        unordered_set<int> h;
        for (auto &c:time) if (c != ':' && !h.count(c - '0')) h.insert(c - '0');
        
        int start = stoi(time.substr(0,2)) * 60 + stoi(time.substr(3));
        int res = start;
        int elapsed = 60*24;
        
        for (auto &n1:h) {
            for (auto &n2:h) {
                if (n1 * 10 + n2 >= 24) continue;
                for (auto &n3:h) {
                    for (auto &n4:h) {
                        if (n3 * 10 + n4 >= 60) continue;
                        
                        auto cur = (n1 * 10 + n2) * 60 + (n3 * 10 + n4);
                        auto curElapsed = (cur-start < 0) ? cur - start + 1440 : cur - start;
                        if (0 < curElapsed && curElapsed < elapsed) {
                            res = cur;
                            elapsed = curElapsed;
                        }
                    }
                }
            }
        }
        return to_string(res/60/10) + to_string(res/60%10) + ":" + to_string(res%60/10) + to_string(res%60%10);
    }
    
    string nextClosestTime(string time) {
        //return nextClosestTime_bruteforce(time);
        return nextClosestTime_allowed(time);
    }
};

int main()
{
    assert(Solution().nextClosestTime("19:34") == "19:39");
    assert(Solution().nextClosestTime("23:59") == "22:22");

    return 0;
}