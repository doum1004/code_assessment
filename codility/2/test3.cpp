#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

/**
//Solution1. One pass iteration
//time: o(n)
//space: o(1)

1. iterate string
1.1. pre = S[i-1], cur = S[i]
1.2. find transformed condition and commit changes(remove). and i -= 2

*/

string solution_replace(string &S) {
    if (S.size() < 1) return S;
    
    for (int i=1; i<(int)S.size(); ++i) {
        char pre = S[i-1];
        auto cur = S[i];
        if ((pre == 'B' && cur == 'A')
        || (pre == 'A' && cur == 'B')
        || (pre == 'C' && cur == 'D')
        || (pre == 'D' && cur == 'C')) {
            S.erase(i-1,2);
            i -= 2;
        }
    }
    
    return S;
}

string solution_onepass(string &S) {
    if (S.size() < 1) return S;
    
    for (int i=1; i<(int)S.size(); ++i) {
        char pre = S[i-1];
        auto cur = S[i];
        if ((pre == 'B' && cur == 'A')
        || (pre == 'A' && cur == 'B')
        || (pre == 'C' && cur == 'D')
        || (pre == 'D' && cur == 'C')) {
            S.erase(i-1,2);
            i -= 2;
        }
    }
    
    return S;
}

string solution(string &S) {
    return solution_replace(S);
    return solution_onepass(S);
}

int main() {
    string input1 = "CBACD";
    assert(solution(input1) == ("C"));
    string input2 = "CABABD";
    assert(solution(input2) == (""));
    return 0;
}