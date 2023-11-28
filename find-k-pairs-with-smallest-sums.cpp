/*
https://leetcode.com/problems/find-k-pairs-with-smallest-sums

Solution. min heap
time: o(klogn)
space: o(n)

*/

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if (k == 0) return {};
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> heap;
        for (int i=0; i<n1; ++i) {
            heap.push({nums1[i] + nums2[0], {i, 0}});
        }

        vector<vector<int>> ans;
        while (k-- && !heap.empty()) {
            auto top = heap.top();
            heap.pop();
            
            auto i = top.second.first;
            auto j = top.second.second;

            ans.push_back({nums1[i], nums2[j]});

            if (j != n2 - 1)
                heap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
        }
        
        return ans;
    }
};