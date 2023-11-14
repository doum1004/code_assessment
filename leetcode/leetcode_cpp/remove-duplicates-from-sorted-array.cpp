#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <set>

using namespace std;

/*
sol1. hash set
time: o(n)
space: o(n)

sol2. two pointers
time: o(n)
space: o(1)

*/

class Solution {
public:
    int removeDuplicates_1(vector<int>& nums) {
        std::set<int> h;
        int i = 0;
        for (int num : nums) {
            if (h.find(num) == h.end()) {
                h.insert(num);
                nums[i++] = num;
            }
        }
        return i;        
    }

    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        int j = 1;
        for (int i=1; i<n; ++i) {
            if (nums[i - 1] != nums[i]) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};

int main()
{
    return 0;
}