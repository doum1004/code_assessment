#include <iostream>
#include <cassert>
#include "../utils.h"

#include <vector>
#include <sstream>

#include <cctype>

using namespace std;

string mostCommonWord(string paragraph, vector<string> banned) {
    unordered_set<string> bannedset(banned.begin(), banned.end());
    unordered_map<string, int> word_count;

    for (char &c: paragraph)
    {
        if (isalpha(c))
            c = tolower(c);
        else
            c = ' ';
    }
    istringstream iss(paragraph);
    string w;
    pair<string, int> ans;
    while (iss >> w)
    {
        if (bannedset.find(w) == bannedset.end() && ++word_count[w] > ans.second)
        {
            ans = pair(w, word_count[w]);
        }
    }

    return ans.first;
}

string mostCommonWord2(string paragraph, vector<string> banned) {
    for (char &c: paragraph)
    {
        if (isalpha(c))
            c = tolower(c);
        else
            c = ' ';
    }
    paragraph += ".";
    
    unordered_set<string> bannedset(banned.begin(), banned.end());
    auto map = unordered_map<string, int>();

    int l = 0, r = 0;
    string ans = "";
    int max = 0;
    for (int i=0; i<paragraph.size(); i++)
    {
        auto c = paragraph.at(i);
        if (!isspace(c) && isalpha(c))
        {
            r++;
        }
        else
        {
            if (l != r)
            {
                auto str = paragraph.substr(l, r - l);
                if (bannedset.find(str) == bannedset.end())
                {
                    map[str]++;
                    if (max < map[str])
                    {
                        ans = str;
                        max = map[str];
                    }
                }
            }
            l = r = i + 1;
        }
    }

    return ans;
}

int main()
{
    assert(mostCommonWord(
        "Bob hit a ball, the hit BALL flew far after it was hit.",
        vector<string>{"hit"}) == "ball");
    assert(mostCommonWord(
        "Bob",
        vector<string>{}) == "bob");
    return 0;
}