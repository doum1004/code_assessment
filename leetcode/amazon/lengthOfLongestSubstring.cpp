#include <iostream>
#include <vector>
#include <cassert>
#include "../../utils.h"

using namespace std;

int lengthOfLongestSubstring2(string s) {
    auto n = s.size();
    if (n < 1) return 0;
    
    auto answer = 0;
    auto map = unordered_map<char, int>();
    for (int i=0, j=0; j<n; j++)
    {
        if (map.find(s.at(j)) != map.end())
        {
            i = max(i, map[s.at(j)]);           
        }
        answer = max(answer, j-i + 1);
        map[s.at(j)] = j + 1;
    }

    return answer; 
}

int lengthOfLongestSubstring3(string s) {
    auto n = s.size();
    if (n < 1) return 0;
    
    auto set = unordered_set<char>();
    
    auto answer = 0, i = 0, j = 0;
    while (i < n && j < n)
    {
        if (set.find(s.at(j)) == set.end())
        {
            set.insert(s.at(j++));
            answer = max(answer, (int)set.size());
        }
        else
        {
            set.erase(s.at(i++));
        }
    }

    return answer; 
}


int lengthOfLongestSubstring(string s) {
    if (s.size() < 1) return 0;

    auto answer = 1;
    
    auto list = vector<char>();
    for (int i=0, j=0; i<s.size(); i++)
    {
        auto it = find(list.begin(), list.end(), s.at(i));
        if (it != list.end() && it - list.begin() >= j++)
        {
            j++;
        }
        list.push_back(s.at(i));
        answer = max(answer, i - j + 1);
    }

    return answer; 
}

int lengthOfLongestSubstring0(string s) {
    if (s.size() < 1) return 0;

    auto answer = 1;
    
    auto list = vector<char>();
    for (int i=0; i<s.size(); i++)
    {
        auto it = find(list.begin(), list.end(), s.at(i));
        if (it != list.end())
        {
            list.erase(list.begin(), it+1);
        }
        list.push_back(s.at(i));
        answer = max(answer, (int)list.size());
    }

    return answer; 
}

int main()
{
    assert(lengthOfLongestSubstring("abcabcbb") == 3);
    assert(lengthOfLongestSubstring("aab") == 2);
    assert(lengthOfLongestSubstring("pwwkew") == 3);
    assert(lengthOfLongestSubstring("ohvhjdml") == 6);
    assert(lengthOfLongestSubstring("abba") == 2);
    return 0;
}