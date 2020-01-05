#include <iostream>
#include <cassert>
#include "../../utils.h"

#include <vector>
#include <sstream>

#include <cctype>

using namespace std;

vector<string> reorderLogFiles(vector<string> logs) {
    vector<string> ans;
    vector<pair<string, string>> letterLogs;
    vector<string> digitLogs;
    for (auto &s : logs) {
        auto i = s.find(' ');
        if (isdigit(s[i + 1]))
            digitLogs.push_back(s);
        else
            letterLogs.emplace_back(s.substr(0, i), s.substr(i+1));
    }
    
    sort(letterLogs.begin(), letterLogs.end(), [&](auto& a, auto& b) {
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    });

    for (auto &p : letterLogs) ans.push_back(p.first + " " + p.second);
    for (auto &s : digitLogs) ans.push_back(s);

    return ans;
}

int main()
{
    assert(reorderLogFiles(
        vector<string> {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"})
        == (vector<string> {"let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"}));
    return 0;
}