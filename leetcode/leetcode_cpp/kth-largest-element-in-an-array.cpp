#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include <set>
#include "../utils.h"

using namespace std;

// https://leetcode.com/problems/kth-largest-element-in-an-array/

// sort (sort, nth_element, partial_sort)
// time: o(nlogn) / o(nlogn) n=last-first / o(nlogm) n =last-first m =middle-first 
// space: o(1)

// heap (minheap and pop if nb exceeds. priority queue, multiset) 
// time: o(nlogk) n * insert(logk)
// space: o(k)

// quickselection (partion + quicksort)
// time: avg( o(n) ) worst o(n^2)

class Solution {
public:
    int findKthLargest_sort(vector<int>& nums, int k) {
        if (false) {
            sort(nums.begin(), nums.end());
            return nums[nums.size() - k];
        }
        else if (false) {
            nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
            return nums[k - 1];
        }
        else {
            partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
            return nums[k - 1];
        }
    }
    
    int findKthLargest_heap(vector<int>& nums, int k) {
        if (false) {
            // priority queue
            auto minHeap = priority_queue<int, vector<int>, greater<int>>();
            for (auto &n : nums) {
                minHeap.push(n);
                if (minHeap.size() > k) minHeap.pop();
            }

            return minHeap.top();
        }
        else {
            // multiset
            auto minHeap = multiset<int>();
            for (auto &n : nums) {
                minHeap.insert(n);
                if (minHeap.size() > k) minHeap.erase(minHeap.begin());
            }
            
            return *minHeap.begin();
        }
    }
    
    int findKthLargest_quickselection(vector<int>& nums, int k) {
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
    
    int findKthLargest(vector<int>& nums, int k) {
        //return findKthLargest_sort(nums, k);
        //return findKthLargest_heap(nums, k);
        return findKthLargest_quickselection(nums, k);
    }

private:
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

int main()
{
    auto input1_1 = vector<int> {3,2,1,5,6,4};
    assert(Solution().findKthLargest(
        input1_1, 2
    ) == (5));
    return 0;
}