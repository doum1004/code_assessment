#include <iostream>
#include <cassert>
#include "../utils.h"

#include <vector>
#include <sstream>

#include <cctype>
#include <stack>

using namespace std;

// https://leetcode.com/problems/3sum/

// Three points
// time: o(n^2) : sort(nlogn) + iterate(i*(l,r))
// space: o(n) vector for ans

// 1. sort then easy to avoid duplicates
// -1 -1 0 1 2

// 2. iterate nums (i). And skip duplicates
// for i; i<n
//  target = -i
//  front = i + 1
//  back = n - 1
//  while (front < back)
//      sum = front + back
//      if (sum > target)
//          back--
//      else if (sum < target)
//          front++
//      else
//          vector<int> triple(3,0)
//          triple[0] = nums[i]
//          triple[1] = nums[front]
//          triple[2] = nums[back]
//          while (front < back && nums[front] == triple[1]) front++;
//          while (front < back && nums[back] == triple[2]) end--;
//  while (i+1 < n && nums[i] == nums[i+1]) i++;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return vector<vector<int>>();
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        for (int i=0; i<nums.size(); ++i) {
            auto target = -nums[i];
            auto l = i+1;
            auto r = nums.size() - 1;
            
            while (l < r) {
                auto sum = nums[l] + nums[r];
                if (sum < target) {
                    l++;
                }
                else if (sum > target) {
                    r--;
                }
                else {
                    vector<int> triple(3, 0);
                    triple[0] = nums[i];
                    triple[1] = nums[l];
                    triple[2] = nums[r];
                    ans.push_back(triple);
                    
                    while (l < r && nums[l] == triple[1]) l++;
                    while (l < r && nums[r] == triple[2]) r--;
                }
            }
            
            while (i+1 < nums.size() && nums[i+1] == nums[i]) i++;
        }
        return ans;
    }
};

int main()
{
    auto input1 = vector<int> {-1, 0, 1, 2, -1, -4};
    auto expect1 = vector<vector<int>>();
    expect1.push_back(vector<int> {-1, 0, 1});
    expect1.push_back(vector<int> {-1, -1, 2});
    assert(Solution().threeSum(input1)
        == expect1);
    return 0;
}