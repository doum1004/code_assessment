#include <iostream>
#include <cassert>
#include "../utils.h"

#include <vector>
#include <sstream>

#include <cctype>

using namespace std;

// https://leetcode.com/problems/reorder-data-in-log-files/

// time: o(nlogn) : sort(nlogn) + o(n) * 3
// space: o(n)

//1. get id
//2. identify num or alpha
//3. save num data, save alpha data
//4. sort alpha data
//5. return merge alpha data and num data

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        if (logs.size() < 2) return logs;
        
        vector<string> numericLogs;
        vector<pair<string, string>> alphaLogs;
        for (auto &log : logs) {
            auto it = log.find(" ");
            if (isdigit(log[it+1])) {
                numericLogs.push_back(log);
            }
            else {
                alphaLogs.push_back({log.substr(0, it), log.substr(it+1)});
            }
        }
        
        sort(alphaLogs.begin(), alphaLogs.end(), [&](auto &a, auto &b) {
            return (a.second == b.second) ? a.first < b.first : a.second < b.second;
        });
        
        vector<string> ans;
        for (auto &log : alphaLogs) ans.push_back(log.first + " " + log.second);
        for (auto &log : numericLogs) ans.push_back(log);
        
        return ans;
    }
};

int main()
{
    auto input1 = vector<string> {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
    assert(Solution().reorderLogFiles(
        input1)
        == (vector<string> {"let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"}));
    return 0;
}