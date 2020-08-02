#include <iostream>
#include <cassert>
#include "../utils.h"

#include <vector>
#include <sstream>
#include <unordered_set>
#include <cctype>

using namespace std;

// Counting
// time: o(B+P): b(banned) + p(paragraph)
// space: o(B+P): b(banned) + c(word of paragraph)

// map for banned vector (better for get)
// iterate string
//  if isalpha lower
//  else replace by ' '

// unordered_map<string, int> wordCount;
// istringstream to read by space
//  if (s not banned && ++wordCount[s] > maxCount)
//      store s, count


class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        for (auto &c : paragraph) {
            if (isalpha(c)) {
                c = tolower(c);
            }
            else {
                c = ' ';
            }
        }
        
        unordered_map<string, int> wordCount;
        pair<string, int> ans;
        
        istringstream iss(paragraph);
        string s;
        while (iss >> s) {
            if (bannedSet.find(s) == bannedSet.end() && ++wordCount[s] > ans.second)
                ans = {s, wordCount[s]};
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
