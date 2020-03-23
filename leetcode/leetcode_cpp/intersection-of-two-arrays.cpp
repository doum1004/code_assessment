#include <iostream>
#include <cassert>

#include <vector>
#include <unordered_set>

using namespace std;

/**
https://leetcode.com/problems/intersection-of-two-arrays/

solution1. put one array and check exist or not
//time: o(n+m)
//space: o(n+m)

solution2. no space with sort
//time: o(nlogn + 2n)
//space: o(1)

1. sort
2. move by two pointers. skip duplications and compare.
2.1 put if same
2.2 if left is smaller l++
2.3 if right is smaller r++

*/

class Solution {
public:
    vector<int> intersection_space(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        for (auto &n:nums1) {
            s.insert(n);
        }
        
        vector<int> res;
        for (auto &n:nums2) {
            if (s.count(n)) {
                res.push_back(n); 
                s.erase(n);
            }
        }
        return res;
    }
    
    vector<int> intersection_nospace(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int len1 = nums1.size(), len2 = nums2.size(), l = 0, r = 0;
        
        vector<int> res;
        while (true) {
            while (l < len1-1 && nums1[l] == nums1[l+1]) l++;
            while (r < len2-1 && nums2[r] == nums2[r+1]) r++;
            
            if (l < len1 && r < len2) {
                if (nums1[l] == nums2[r]) {
                    res.push_back(nums1[l]);
                    l++;
                    r++;
                }
                else if (nums1[l] < nums2[r]) l++;
                else r++;
            }
            else break;
        }
        
        return res;
    }
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //return intersection_space(nums1, nums2);
        return intersection_nospace(nums1, nums2);
    }
};

int main()
{
    auto input1_1 = vector<int>{1,2,2,1};
    auto input1_2 = vector<int>{2,2};
    assert(Solution().intersection(input1_1, input1_2) == (vector<int>{2}));

    auto input2_1 = vector<int>{4,9,5};
    auto input2_2 = vector<int>{9,4,9,8,4};
    assert(Solution().intersection(input2_1, input2_2) == (vector<int>{4,9}));

    return 0;
}