#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

/**
https://leetcode.com/problems/permutations/

soltuion1. permute_nextpermute. two pointers (swap, reverse)
// time; o(n*n!). n(len(nums))*n!(all number of permutation)
// space: o(1). answer(n!)

1. itearte in factorial (n)
2. find l idx from last (nums[l] < nums[l+1])
2.1 if l is none. break iteration
2.2 else find r idx from l (nums[r] > nums[l], most right most)
2.2.1 swap l,r. and reverse(l+1,r). add nums into answer

solution2. backtracking(change, recursion, undo)
// time: o(n*n!)
// space: o(n!) recursion

In recursion(nums, i, ans)
if i == nums.size. add in ans
else iterate j (i to end). swap(i,j) and call recursion(num, i+1)


*/

class Solution {
public:       
    vector<vector<int>> permute_nextpermute(vector<int>& nums) {
        // int total = 1;
        // for (int i=2; i<=n_nums; ++i) {
        //     total *= i;
        // }
        int n = nums.size();
        
        vector<vector<int>> res;
        res.push_back(nums);
        
        while (true) {
            int l, r;
            for (l=n-2; l>=0; --l) {
                if (nums[l] < nums[l+1]) break;
            }
            
            if (l == -1) {
                reverse(nums.begin(), nums.end());
            }
            else {
                for (r=l+1; r<n; ++r) {
                    if (nums[r] < nums[l]) break;
                }
                r--;
                swap(nums[l], nums[r]);
                reverse(nums.begin()+l+1, nums.end());
            }
            if (nums == res[0]) break;
            res.push_back(nums);
        }
        
        return res;     
    }
    
    void permute_recursion(vector<int>& nums, int i, vector<vector<int>>& res) {
        int n = nums.size();
        if (i == n) {
            res.push_back(nums);
        }
        else {
            for (int j=i; j<n; ++j) {
                swap(nums[i], nums[j]);
                permute_recursion(nums, i+1, res);
                swap(nums[i], nums[j]);
            }
        }
    }
    
    vector<vector<int>> permute_backtracking(vector<int>& nums) {
        vector<vector<int>> res;
        permute_recursion(nums, 0, res);
        return res;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        //return permute_nextpermute(nums);
        return permute_backtracking(nums);
    }
};

int main()
{
    auto input1 = vector<int> {1,2,3};
    auto output1 = vector<vector<int>> {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};
    auto result1 = Solution().permute(input1);
    sort(output1.begin(), output1.end());
    sort(result1.begin(), result1.end());
    assert(output1 == (result1));
   
    return 0;
}