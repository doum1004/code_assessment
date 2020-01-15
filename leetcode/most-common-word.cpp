#include <iostream>
#include <cassert>
#include "../utils.h"

#include <vector>
#include <sstream>
#include <unordered_set>
#include <cctype>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // set, map, pair, istringstream
        // o(banded+p) = o(banded) + o(p) + o(p) + o(1)
        // o(banded+p) = o(banded) + o(p)
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        for (auto &c : paragraph) {
            if (isalpha(c)) {
                c = tolower(c);
            }
            else {
                c = ' ';
            }
        }

        unordered_map<string, int> matched;

        pair<string, int> ans;
        istringstream iss(paragraph);
        string s;
        while (iss >> s) {
            if (bannedSet.find(s) == bannedSet.end() && ++matched[s] > ans.second) {
                ans = pair(s, matched[s]);
            }
        }

        return ans.first;
    }
};

int main()
{
    auto input1 = vector<string>{"hit"};
    assert(Solution().mostCommonWord(
        "Bob hit a ball, the hit BALL flew far after it was hit.",
        input1) == "ball");

    auto input2 = vector<string>{""};
    assert(Solution().mostCommonWord(
        "Bob",
        input2) == "bob");
    return 0;
}