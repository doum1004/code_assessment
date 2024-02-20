/*
https://leetcode.com/problems/find-peak-element

Solution1. linear
time: o(n)
space: o(1)

Solution2. binary search
time: o(logn)
space: o(1)

*/
class Solution {
public:
    int findPeakElement_linear(vector<int>& nums) {
        for (int i=0; i<nums.size()-1; ++i)
            if (nums[i] > nums[i+1]) return i;
        return nums.size()-1;
    }
    int findPeakElement_bs(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = nums.size()-1;
        while(low < high){
            int mid = low + (high - low) / 2;
            if(nums[mid] > nums[mid+1]){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
    int findPeakElement(vector<int>& nums) {
        return findPeakElement_bs(nums);
    }
};