#include <iostream>
#include <unordered_map>
#include <cassert>

using namespace std;

/**
https://leetcode.com/problems/first-unique-character-in-a-string/

// solution1. count in map and iterate again to find only 1 count
// time: o(n). 2n
// space: o(m)

// solution2. count in array
// time: o(n). 2n
// space: o(26)

*/

class Solution {
public:
    int firstUniqChar_map(string& s) {
        unordered_map<char,int> m;
        for (auto &c:s) {
            m[c]++;
        }
        for (int i=0; i<s.size(); ++i) {
            if (m[s[i]] == 1) return i;
        }
        return -1;
    }
    
    int firstUniqChar_array(string& s) {
        int arr[26] = {0};
        for (auto &c:s) {
            arr[c-'a']++;
        }
        
        for (int i=0; i<s.size(); ++i) {
            if (arr[s[i] - 'a'] == 1) return i;
        }
        
        return -1;
    }
    
    int firstUniqChar(string s) {
        //return firstUniqChar_map(s);
        return firstUniqChar_array(s);
    }
};

int main()
{
    assert(Solution().firstUniqChar("leetcode") == 0);
    assert(Solution().firstUniqChar("loveleetcode") == 2);
    return 0;
}