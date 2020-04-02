#include <iostream>
#include <cassert>

#include <unordered_map>

using namespace std;

/**
https://leetcode.com/problems/logger-rate-limiter/

Solution1. store in hashmap
time: o(1)
space: o(M) m: size of all incoming messages

*/

class Logger {
public:
    unordered_map<string, int> h_;
    /** Initialize your data structure here. */
    Logger() {
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (timestamp < h_[message]) return false;
        h_[message] = timestamp + 10;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */

int main()
{
    auto logger = Logger();
    assert(logger.shouldPrintMessage(1, "foo") == (true));
    assert(logger.shouldPrintMessage(2, "bar") == (true));
    assert(logger.shouldPrintMessage(3,"foo") == (false));
    assert(logger.shouldPrintMessage(8,"bar") == (false));
    assert(logger.shouldPrintMessage(10,"foo") == (false));
    assert(logger.shouldPrintMessage(11,"foo") == (true));

    return 0;
}
