/*
https://leetcode.com/problems/kth-largest-element-in-an-array

solution1. sort (sort,  nth_element, partial_sort)
time: o(nlogn)
space: o(1)

solution2. heap (min/max heap, multiset)

solution3. quickselection
time: o(n^2). worst: o(n^2) best: o(n)

*/


class Solution {
public:
    int findKthLargest_1_1(vector<int>& nums, int k) {
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

    int findKthLargest_2(vector<int>& nums, int k) {
        auto minHeap = priority_queue<int, vector<int>, greater<int>()>();
        for (int n : nums) {
            minHeap.push(n);
            if (minHeap.size() > k) minHeap.pop();
        }
        return minHeap.top();
    }

    int findKthLargest_2_1(vector<int>& nums, int k) {
        auto minHeap = multiset<int>();
        for (int n : nums) {
            minHeap.insert(n);
            if (minHeap.size() > k) minHeap.erase(minHeap.begin());
        }
        return *minHeap.begin();
    }

    int findKthLargest_3(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k);
    }

    int quickSelect(vector<int>& nums, int l, int r, int k) {
        int tar = nums[l];
        int i = l;
        int j = r;
        while (l < r) {
            while (i<j && nums[j] >= tar)
                j--;
            if (i<j)
                nums[i++] = nums[j]
            while (i<j && nums[i] <= tar)
                i++;
            if (i<j)
                nums[j--] = nums[i];
        }
        nums[i] = tar;
        if (i == k)
            return tar;
        if (i > k)
            quickSelect(nums, l, i-1, k);
        else
            quickSelect(nums, i+1, j, k);
        
    }

    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest_1_1(nums, k);
    }
};


class Solution {
public:
    int findKthLargest_1(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[k-1];
    }

    int findKthLargest_1_2(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        return nums[k-1];
    }

    int findKthLargest_2(vector<int>& nums, int k) {
        priority_queue<int> q;
        for (auto num : nums)
            q.push(num);
        while (k-1) {
            q.pop();
            k--;
        }
        return q.top();
    }

    int quickSelect(vector<int>& nums, int l, int r, int k) {
        int tar = nums[l];
        int i = l;
        int j = r;
        while (i < j) {
            while (i < j && nums[j] >= tar)
                j--;
            if (i < j)
                nums[i++] = nums[j];
            while (i < j && nums[i] <= tar)
                i++;
            if (i < j)
                nums[j--] = nums[i];
        }
        nums[i] = tar;
        if (i == k)
            return tar;
        if (k > k)
            return quickSelect(nums, l, i - 1, k);
        else
            return quickSelect(nums, i+1, r, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        while (l<=r) {
            auto pivot = partition(nums, l, r);
            if (pivot == k - 1) {
                return nums[pivot];
            }
            else if (pivot > k - 1) {
                r = pivot - 1;
            }
            else {
                l = pivot + 1;
            }
        }
        
        return INT_MIN;
    }

    int partition(vector<int>& nums, int l, int r) {
        if (l == r) return l;
        int idx = l;
        int randpivot = rand() % (r - l) + l;
        swap(nums[randpivot], nums[r]);
        
        for (int i=l; i<r; ++i) {
            if (nums[i] > nums[r]) {
                swap(nums[i], nums[idx++]);
            }
        }
        swap(nums[idx], nums[r]);
        return idx;
    }
};