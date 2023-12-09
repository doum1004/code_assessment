/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

Solution1. iterate
time: o(n)
space: o(1)

Solution2. Bin search
time: o(logn)
space: o(1)
loop
1) if nums[l] < nums[r] return nums[l]
2) if nums[l] > nums[r]
2.1) if nums[m] < nums[r] r= m
2.2) if nums[m] > nums[r] l = m+1
*/
class Solution {
public:
    int findMin_1(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        for (int i=0; i<nums.size(); ++i) {
            if (i == 0) {
                if (nums[0] < nums[nums.size()-1]) return nums[0];
            }
            else if (nums[i-1] > nums[i]) {
                return nums[i];
            }
        }
        return -1;            
    }
    int findMin_2(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int l = 0, r = n-1;
        while (l <= r) {
            int m = l + (r-l) / 2;
            //cout << l << "," << r << ":" << m << endl;
            if (nums[l] < nums[r]) return nums[l];
            if (nums[m] < nums[r]) r = m;
            else l = m + 1;
        }
        return nums[r];
    }
    int findMin(vector<int>& nums) {
        return findMin_2(nums);
    }
};