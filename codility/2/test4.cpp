#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/**
//Solution1. sliding window (with map counter)
//time: o(n). nb set country(n) + sliding window iteration(2n)
//space: o(L). L(number of unique locations)

1. find all set of locations. n_location
2. sliding window iteration l=0, r=0
2. for r in range(0,n)
2.1 add counter in hashmap
2.2 loop (l<=r && hashmap size is same or larger)
2.2.1 store shortest vacation (r-l+1)
2.2.2 decrease of count on A[l] and erase hashmap if empty. And move l++

*/

int solution_slidingwindow(vector<int> &A) {
    int n = A.size();
    if (n < 1) return 0;
    
    unordered_set<int> locations;
    for (auto &l:A) if (!locations.count(l)) locations.insert(l);
    int n_locations = locations.size();
    
    unordered_map<int,int> counter;
    int l=0, res = n; // shortest vacation
    for (int r=0; r<n; ++r) {
        counter[A[r]]++;
        
        while (l<=r && (int)counter.size() == n_locations) {
            res = min(res, r-l+1);
            if (--counter[A[l]] == 0) counter.erase(A[l]);
            l++;
        }
    }
    return res;
}

int solution(vector<int> &A) {
    return solution_slidingwindow(A);
}

int main() {
    auto input1 = vector<int>{7,3,7,3,1,3,4,1};
    assert(solution(input1) == (5));

    auto input2 = vector<int>{6,6,6,6,7,3,7,3,1,3,4,1,6,6};
    assert(solution(input2) == (7));

    return 0;
}