#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include "../../utils.h"

using namespace std;

string twoStrings(string s1, string s2) {
    auto result = false;

    for (auto c : "abcdefghijklmnopqrstuvwxyz")
    {
        if (s1.find(c) != string::npos && s2.find(c) != string::npos)
        {
            result = true;
            break;
        }
    }
    // auto s_set = unordered_set<char>();
    // for (auto c : s1)
    // {
    //     s_set.insert(c);
    // }

    // for (auto c : s2)
    // {
    //     if (s_set.find(c) != s_set.end())
    //     {
    //         result = true;
    //         break;
    //     }
    // }

    if (result)
        return "YES";
    else
        return "NO";
}

int main() {
    cout << twoStrings("hello", "world") << endl; // Yes
    cout << twoStrings("hi", "world") << endl; // Yes
    return 0;
}