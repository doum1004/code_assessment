#include <iostream>
#include <cassert>

#include <unordered_set>

using namespace std;

/**
https://leetcode.com/problems/cracking-the-safe/

Solution1. De Bruijn Sequence. (crack the combination lock)
find all combination contained answer.
ex) n=2, k=2. passowrd could be(k:0,1) 00,01,10,11
one soultion would be: 00110
[0]:0 -> no operation
[1]:0 -> 00
[2]:1 -> 01
[3]:1 -> 11
[4]:0 -> 10

https://www.youtube.com/watch?v=iPLQgXUiU14
https://leetcode.com/problems/cracking-the-safe/discuss/381122/Can-someone-explain-the-damn-question-please
time: o(k*k^n):
space: o(k*k^n): dfs
*/

class Solution {
public:
    bool dfs(int n, int k, int maxSize, unordered_set<string>& v, string& res) {
        if (v.size() == maxSize) return true;
        for (int i=0; i<k; ++i) {
            res += '0' + i;
            string pwd = res.substr(res.length()-n);
            if (!v.count(pwd)) {
                v.insert(pwd);
                if (dfs(n,k,maxSize,v,res)) return true;
                v.erase(pwd);
            }
            res.pop_back();
        }
        return false;
    }
    
    string crackSafe(int n, int k) {
        string res = string(n, '0');
        unordered_set<string> v;
        v.insert(res);
        dfs(n,k,pow(k,n),v,res);
        return res;
    }
};

int main()
{
    return 0;
}
