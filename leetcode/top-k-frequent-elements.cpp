#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

/**
https://leetcode.com/problems/top-k-frequent-elements/

// Solution1. count and max-heap to order
// time: o(n + mlogm)
// space: o(2m). map(m) + heap(m)

// Solution2. count and min-heap to order
// time: o(n + mlogk)
// space: o(m + k). map(m) + heap(k)

// Solution3. Bucket sort
// time: o(n). buildmap(n) + bucket(m)
// space: o(m+n). map(m) + bucket(n)

*/

class Solution {
private:
    struct comp_maxheap{
        bool operator()(const pair<int, int>&a, const pair<int, int>&b) {
            return (a.second < b.second);    
        }
    };
    
    struct comp_minheap{
        bool operator()(const pair<int, int>&a, const pair<int, int>&b) {
            return a.second > b.second;    
        }
    };
    
public:
    vector<int> topKFrequent_maxheap(vector<int>& nums, int k) {
        unordered_map<int, int> m; // space(n)
        for (auto &n:nums) { // time(n)
            m[n]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int,int>>, comp_maxheap> q; // space(m)
        for (auto &node:m) { // time(m)
            q.push(node); //logm
        }
        
        vector<int> list;
        for (int i=1; i<=k; ++i) { // time(k)
            list.push_back(q.top().first);
            q.pop();
        }
        return list;
    }
    
    vector<int> topKFrequent_minheap(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto &n:nums) {
            m[n]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp_minheap> q;
        for (auto &node:m) {
            q.push(node);
            if (q.size() > k) q.pop();
        }
        
        vector<int> ans;
        for (int i=1; i<=k; ++i) {
            ans.push_back(q.top().first);
            q.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
    
    vector<int> topKFrequent_bucket(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto &n:nums) {
            m[n]++;
        }
        
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto &node:m) {
            bucket[node.second].push_back(node.first);
        }
        
        vector<int> ans;
        for (int i=bucket.size()-1; i>=0; --i) {
            for (auto &item:bucket[i]) {
                ans.push_back(item);
                if (ans.size() == k) return ans;
            }
        }
        return ans;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //return topKFrequent_maxheap(nums, k);
        //return topKFrequent_minheap(nums, k);
        return topKFrequent_bucket(nums, k);
    }
};

int main()
{
    auto input1 = vector<int> {1,1,1,2,2,3};
    auto expact1 = vector<int> {1,2};
    assert(Solution().topKFrequent(input1, 2) == (expact1));
    auto input2 = vector<int> {1};
    auto expact2 = vector<int> {1};
    assert(Solution().topKFrequent(input2, 1) == (expact2));
    return 0;
}