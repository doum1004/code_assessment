#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

/**
https://leetcode.com/problems/merge-sorted-array/

// Solution1.
// time: o(n)

// Solution1. Brute force
// time: o(n*m)
// space: o(m+n)

// Solution2. Two paths
// time: o(n+m)
// space: o(n+m)
n(max(n, m))
m = num1.size()
n = num2.size()
i = 0, j = 0

num3(n+m)
while i < m && j < n
	if (num1[i] <= num2[j])
		num3.push_back(num1[i++])
	else
		num3.push_back(num2[j++])

while i < m
	num3.push_back(num1[i++])

while j < n
	num3.push_back(num2[j++])

p = 0
while p < m+n
	num1[p] = num3[p]


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
    }
};

// Solution3. Two paths with no additional space
// time: o(n+m)
// space: o(1)

*/

class Solution {
public:
public:
    void merge_two_paths(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] >= nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
        printf("%d", i);
    }

    void merge_sort(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int j = 0, i = m; j<n; j++){
            nums1[i] = nums2[j];
            i++;
        }
        sort(nums1.begin(),nums1.end());
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        merge_two_paths(nums1, m, nums2, n);
    }
};

int main()
{
    auto input1 = vector<int> {1,2,3,0,0,0};
    auto input2 = vector<int> {2,5,6};
    Solution().merge(input1, 3, input2, 3);
    //assert(input1 == vector<int> {1,2,2,3,5,6});
    return 0;
}