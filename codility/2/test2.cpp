#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int solution2(vector<int>& A, int X) {
    int N = A.size();
    if (N == 0) return -1;
    
    int l = 0, r = N - 1, m = 0;
    while (l <= r) {
        m = (l + r) / 2;
        if (A[m] == X) return m;
        else if (A[m] > X) r = m - 1;
        else  l = m + 1;
    }
    return -1;
}

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

int custom_lower_bound(vector<int>& nums, int target) {
    int l=0, r=nums.size()-1;
    while (l<r) {
        int m = (r-l)/2+l;
        if (nums[m] < target) l = m+1;
        else r = m;
    }
    if (nums[l] == target) return l;
    return -1;
}

int custom_upper_bound(vector<int>& nums, int target) {
    int l=0,r=nums.size()-1;
    while (l<r) {
        int m=(r-l+1)/2+l;
        if (nums[m] <= target) l = m;
        else r = m-1;
    }
    if (nums[r] == target) return r;
    return -1;
}

int main() {
    auto input1 = vector<int> {1,2,5,9,9};
    //assert(solution(input1, 1) == 0);
    assert(solution2(input1, -1) == 0);
    return 0;
}