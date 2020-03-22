#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int solution(vector<int>& A, int X) {
    int N = A.size();
    if (N == 0) {
        return -1;
    }
    int l = 0;
    int r = N - 1;
    while (l < r) {
        int m = (l + r + 1) / 2;
        if (A[m] > X) {
            r = m - 1;
        } else {
            l = m;
        }
    }
    if (A[l] == X) {
        return l;
    }
    return -1;
}

int main() {
    auto input1 = vector<int> {1,2,5,9,9};
    assert(solution(input1, 4) == -1);
    return 0;
}