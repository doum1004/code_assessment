#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

/**
https://leetcode.com/problems/fizz-buzz/

// Solution1. iteration 1 to n and put str
// time: o(n)
// space: o(1) answer

// Solution2. iteration 1 to n and put str (by dict)
// time: o(n)
// space: o(1) answer

*/

class Solution {
public:
    vector<string> fizzBuzz_solution1(int n) {
        vector<string> res;
        for (int i=1; i<=n; ++i) {
            string str;
            if (i % 3 == 0) {
                str += "Fizz";
            }
            if (i % 5 == 0) {
                str += "Buzz";
            }
            if (str.empty()) {
                str = to_string(i);
            }
            res.push_back(str);
        }
        return res;
    }
    
    vector<string> fizzBuzz_solution2(int n) {
        map<int, string> dict;
        dict[3] = "Fizz";
        dict[5] = "Buzz";
        
        vector<string> res;
        for (int i=1; i<=n; ++i) {
            string str;
            for (auto key:dict) {
                if (i % key.first == 0) {
                    str += key.second;
                }
            }
            
            if (str.empty()) {
                str = to_string(i);
            }
            res.push_back(str);
        }
        return res;
    }
    
    vector<string> fizzBuzz(int n) {
        return fizzBuzz_solution1(n);
        //return fizzBuzz_solution2(n);
    }
};

int main()
{
    auto expact1 = vector<string> {"1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz","16","17"};
    assert(Solution().fizzBuzz(17) == (expact1));
    return 0;
}