#include <iostream>
#include <cassert>

#include <stack>

using namespace std;

/**
https://leetcode.com/problems/push-dominoes/

// Solution1. iterate and save in stack (better to do it in two pointers instead of saving it)
// time: o(n) : n + m(number .)
// space: o(m) : stack
1. iterate from begining to face 'L' or 'R'.
2. push all index till 'L' or 'R'
3. if it faces 'L', then make all stacks 'L'
4. if it faces 'R', remove all in stack. and make a flag and put all index after in stack
    5. if they face 'R', make all 'R' in stack. if they face 'L' make after R and L

// Solution2. two pointers. find pattern
// time: o(n). n(l) + n(r)
// space: o(1)
1. add L in the beginning and R at the end
ex) .L.R. -> 'L'.L.R.'R'
2. iterate string till the 'L' or 'R' appear. And do work for the pattern
3. return substr to extract of first and last char

L...L LLLLL add L between
R...R RRRRR add R between
L...R L...R do nothing shift L to R
R...L RR.LL add R and L expect middle in odd
R..L RRLL same as above

*/

class Solution {
public:
    string pushDominoes_stack(string &dominoes) {
        int n = dominoes.size();
        stack<int> s;
        
        bool rFlag = false;
        for (int i=0; i<dominoes.size(); ++i) {
            if (dominoes[i] == 'L') {
                if (!rFlag) {
                    while (!s.empty()) {
                        dominoes[s.top()] = 'L';
                        s.pop();
                    }
                }
                else {
                    int half = s.size() / 2;
                    auto odd = s.size() % 2 == 1;
                    
                    int i = 0;
                    while (!s.empty()) {
                        cout << s.size() << "," << half << endl;
                        if (++i <= half) dominoes[s.top()] = 'L';
                        else if (s.size() <= half) dominoes[s.top()] = 'R';
                        s.pop();
                    }
                }
                rFlag = false;
            }
            else if (dominoes[i] == 'R') {
                while (!s.empty()) {
                    if (rFlag) dominoes[s.top()] = 'R';
                    s.pop();
                }
                rFlag = true;
            }
            else {
                s.push(i);
            }
        }
        
        if (rFlag) {
            while (!s.empty()) {
                dominoes[s.top()] = 'R';
                s.pop();
            }
        }
        
        return dominoes;
    }
    
    string pushDominoes_twopointers(string &dominoes) {
        if (dominoes.size() < 1) return "";
        
        dominoes = "L" + dominoes + "R";
        int l=0, r=0;
        for (r=1;r<dominoes.size(); ++r) {
            if (dominoes[r] == '.') continue;
            if (dominoes[r] == dominoes[l]) {
                while (l<r) {
                    dominoes[++l] = dominoes[r];
                }
            }
            else if (dominoes[r] == 'L') {
                int mid = (r-l-1) / 2;
                int mid_l = mid+l;
                int mid_r = r-mid;
                while (l<r) {
                    l++;
                    if (l <= mid_l) dominoes[l] = 'R';
                    else if (l >= mid_r) dominoes[l] = 'L';
                }
            }
            else {
                l = r;
            }
        }
        
        return dominoes.substr(1, dominoes.size()-2);
    }
    
    string pushDominoes(string dominoes) {
        //return pushDominoes_stack(dominoes);
        return pushDominoes_twopointers(dominoes);
    }
};

int main()
{
    assert(Solution().pushDominoes(".L.R...LR..L..")
        == "LL.RR.LLRRLL..");
    assert(Solution().pushDominoes("RR.L")
        == "RR.L");

    return 0;
}