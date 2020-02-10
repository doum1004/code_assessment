#include <iostream>
#include <cassert>

#include <stack>

using namespace std;

/**
https://leetcode.com/problems/push-dominoes/

".L.R...LR..L.."
"LL.RR.LLRRLL.."


// Solution1. iterate and save in stack
// time: o(n) : n + m(number .)
// space: o(m) : stack
1. iterate from begining to face 'L' or 'R'.
2. push all index till 'L' or 'R'
3. if it faces 'L', then make all stacks 'L'
4. if it faces 'R', remove all in stack. and make a flag and put all index after in stack
    5. if they face 'R', make all 'R' in stack. if they face 'L' make after R and L

// Solution2. two pointers
// time: o(n) : n + n
// space: o(1) : o(1) + 2

L...L = LLLLL
L...R = L...R
R...R = RRRRR
R...L = RR.LL
R....L = RRRLLL


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
    
    string pushDominoes_two_pointers(string &dominoes) {
        int n = dominoes.size();
        if (n < 2) return dominoes;
        dominoes = "L" + dominoes + "R";
        
        int i,j;
        for (i=0,j=1;j<dominoes.size();++j) {
            if (dominoes[j] == '.') continue;
            if (dominoes[i] == dominoes[j]) {
                while (++i < j) {
                    dominoes[i] = dominoes[j];
                }
            }
            else if (dominoes[i] == 'R') {
                //R...L = RR.LL
                //12345 3
                //R....L = RRRLLL
                //123456 4
                int len = j - i - 1;
                int half1 = i + len/2;
                int half2 = j - len/2;
                while (++i < j) {
                    if (i <= half1) dominoes[i] = 'R';
                    if (i >= half2) dominoes[i] = 'L';
                }
            }
            else {
                i = j;
            }
        }
        
        return dominoes.substr(1,n);
    }
    
    string pushDominoes(string dominoes) {
        //return pushDominoes_stack(dominoes);
        return pushDominoes_two_pointers(dominoes);
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