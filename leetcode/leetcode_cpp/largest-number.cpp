#include <iostream>
#include <cassert>

#include <vector>

using namespace std;

/**
https://leetcode.com/problems/largest-number/

// Solution1. Compare a+b, b+a
//time: o(n+nlogn). vector str(n) + sort(nlogn)
//space: o(n). vector

*/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.size() < 1) return "";
        
        vector<string> strs(nums.size());
        for (int i=0; i<nums.size(); ++i)
            strs[i] = to_string(nums[i]);
        
        sort(strs.begin(), strs.end(), [&](const auto &a, const auto &b){
            return a + b > b + a;
        });
        if (strs[0] == "0") return "0";
        
        //string res = accumulate(strs.begin(), strs.end(), string(), [](string &r, string &a){return r + a;});
        string res;
        for (auto &s:strs) res += s;
        return res;
    }
};

int main()
{
    auto input1 = vector<int>{3,30,34,5,9};
    assert(Solution().largestNumber(input1) == ("9534330"));

    return 0;
}
