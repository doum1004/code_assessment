#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

/**

//soltuion1. sort with vector
//time: o(nlogn). n(nb of digits)
//space: o(n). vector

//solution2. bucket sort
//time: o(n). store in bucket(n, nb of digits) + bucket to int(n)
//space: o(1). bucket size(10)

 */

int solution_simplesort(int N) {
    vector<int> list;
    while (N) {
        list.push_back(N % 10);
        N /= 10;
    }
    sort(list.begin(), list.end(), greater<int>());
    int res = 0;
    for (auto &n:list) {
        res = res * 10 + (n);
    }
    return res;
}

int solution_bucketsort(int N) {
    int bucket[10] = {0};
    
    string s = to_string(N);
    for (auto &c: s) {
        bucket[c - '0']++;
    }
    
    int res = 0;
    for (int i=9; i>=0; --i) {
        while (bucket[i]--) {
            res = res * 10 + i;
        }
    }
    return res;
}

int solution(int N) {
    //return solution_simplesort(N);
    return solution_bucketsort(N);
}

int main() {
    assert(solution(123) == (321));
    assert(solution(355) == (553));
    return 0;
}