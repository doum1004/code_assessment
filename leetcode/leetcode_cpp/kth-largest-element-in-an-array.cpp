/*
https://leetcode.com/problems/kth-largest-element-in-an-array

1. sort, nth_element, partial sort
time: o(nlogn)
space: o(1)

2. priority_queue
time: o(nlogn)
space: o(n)

3. quick selection
https://www.youtube.com/watch?v=XEmy13g1Qxc
time: o(n^2) best o(n)
space: o(n)


*/
class Solution {
public:
    int findKthLargest_1(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
    int findKthLargest_1_2(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k - 1];
    }
    int findKthLargest_1_3(vector<int>& nums, int k) {
        partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
        return nums[k - 1];
    }
    int findKthLargest_2_1(vector<int>& nums, int k) {
        // max heap
        priority_queue<int> pq;
        for (int num : nums) pq.push(num);
        while (k > 1) {
            k -= 1;
            pq.pop();
        }
        return pq.top();
    }
    int findKthLargest_2_2(vector<int>& nums, int k) {
        // min heap
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
    int findKthLargest_3(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            auto pivot = partition(nums, l, r);
            if (pivot == k - 1) return nums[pivot];
            else if (pivot > k - 1) r = pivot - 1;
            else l = pivot + 1;
        }
        return 0;
    }
    int partition(vector<int>& nums, int l, int r) {
        if (l == r) return l;
        int idx = l;
        // rand pivot (optional)
        int randpivot = rand() % (r-l) + l;
        swap(nums[randpivot], nums[r]);
        for (int i=l; i<r; ++i) {
            if (nums[i] > nums[r]) swap(nums[i], nums[idx++]);
        }
        swap(nums[idx], nums[r]);
        return idx;
    }
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest_3(nums, k);        
    }
};