/*
https://leetcode.com/problems/find-k-pairs-with-smallest-sums

Solution. min heap
time: o(klogn)
space: o(n)

ex) [1, 7, 11] [2, 4, 6]
(3 (0,0)) (9 (1, 0)) (13 (2, 0)) -> pop: (3 (0,0))
(9 (1, 0)) (13 (2, 0)) -> push: (5, (0, 1))
(5, (0, 1)) (9 (1, 0)) (13 (2, 0)) -> pop (5, (0,1))
(9 (1, 0)) (13 (2, 0)) -> push: (7, (0, 2))
(7, (0, 2)) (9 (1, 0)) (13 (2, 0)) -> pop (7, (0,2))
(9 (1, 0)) (13 (2, 0)) -> pop (9, (1,0))
(13 (2, 0)) -> push: (11, (1, 1))
(11, (1, 1)) (13 (2, 0)) -> pop (11, (1,1))
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