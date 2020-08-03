#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include <set>

using namespace std;

// https://leetcode.com/problems/k-closest-points-to-origin/

// sort (sort, nth_element, partial_sort)
// time: o(nlogn) / o(nlogn) n=last-first / o(nlogm) n =last-first m =middle-first 
// space: o(1)

// heap (minheap and pop if nb exceeds. priority queue, multiset) 
// time: o(nlogk) n * insert(logk)
// space: o(k)

// quickselection (partion + quicksort)
// time: avg( o(n) ) worst o(n^2)


// dist = square(x * x + y * y)

// sort
// time: o(nlogn)
// space: o(1)

// heap
// time: o(nlogn) insert(logn) * n
// space: o(k)

// quickselection
// time: avg o(n) , o(n^2)
// space: o(1)
// partioning(pivot), quicksort


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int mode = 5;
        if (mode == 0) {
            // o(nlogn), o(1)
            sort(points.begin(), points.end(), [&](auto &a, auto &b){
                return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
            });
            return vector<vector<int>>(points.begin(), points.begin() + K);
        }
        else if (mode == 1) {
            // o(NlogN), o(1). N=last-first
            nth_element(points.begin(), points.begin() + K - 1, points.end(), [&](auto &a, auto &b){
                return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
            });
            return vector<vector<int>>(points.begin(), points.begin() + K);
        }
        else if (mode == 2) {
            // o(NlogM), o(1). N=last-first, M=middle-first
            partial_sort(points.begin(), points.begin() + K, points.end(), [&](auto &a, auto &b){
                return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
            });
            return vector<vector<int>>(points.begin(), points.begin() + K);
        }
        else if (mode == 3) {
            // max-heap. o(nlogk + k), o(k)
            auto compare_less = [](auto &a, auto &b) {
                return   (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
            };
            priority_queue<vector<int>, vector<vector<int>>, decltype(compare_less)> pq(compare_less);
            for (auto &p:points) {
                pq.push(p);
                if (pq.size() > K) pq.pop();
            }

            vector<vector<int>> res;
            while (!pq.empty()) {
                res.push_back(pq.top());
                pq.pop();
            }
            return res;
        }
        else if (mode == 4) {
            // min-heap. o(nlogn + n), o(n)
            auto compare_greater = [](auto &a, auto &b) {
                return (a[0] * a[0] + a[1] * a[1]) > (b[0] * b[0] + b[1] * b[1]);
            };
            priority_queue<vector<int>, vector<vector<int>>, decltype(compare_greater)> pq(compare_greater);
            for (auto &p:points) {
                pq.push(p);
            }

            vector<vector<int>> res;
            for (int i=0; i<K; ++i) {
                res.push_back(pq.top());
                pq.pop();
            }
            return res;
        }
        else if (mode == 5) {
            // quick selection
            // partitioning, bin search. avg: o(n). worst: o(n^2)
            
            auto partition = [](vector<vector<int>>& points, int l, int r) {
                if (l == r) return l;
                int randPivot = rand() % (r - l) + l;
                swap(points[randPivot], points[r]);
                int idx = l;
                while (l < r) {
                    auto a = points[l];
                    auto b = points[r];
                    if (a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1]) {
                        swap(points[idx++], points[l]);
                    }
                    l++;
                }
                swap(points[idx], points[r]);
                return idx;
            };
            
            int l = 0, r = points.size() - 1;
            vector<vector<int>> res;
            while (l<=r) {
                auto pivot = partition(points, l, r);
                if (pivot == K - 1) {
                    for (int i=0; i<K; ++i) {
                        res.push_back(points[i]);
                    }
                    return res;
                }
                else if (pivot < K - 1) {
                    l = pivot + 1;
                }
                else {
                    r = pivot - 1;
                }
            }
        }
        return {};
    }
    }
    
    vector<vector<int>> kClosest_heap_priorityqueue(vector<vector<int>>& points, int K) {
        vector<vector<int>> ans;
        if (false) {
            // max-heap
            priority_queue<vector<int>, vector<vector<int>>, compare_less> pq;
            for (auto &point : points) {
                pq.push(point);
                if (pq.size() > K) pq.pop();
            }
            
            while (!pq.empty()) {
                ans.push_back(pq.top());
                pq.pop();
            }
        }
        else {
            // min-heap
            priority_queue<vector<int>, vector<vector<int>>, compare_greater> pq;
            for (auto &point : points) {
                pq.push(point);
            }
            
            for (int i=0; i<K; ++i) {
                ans.push_back(pq.top());
                pq.pop();
            }
        }
        return ans;
    }
    
    vector<vector<int>> kClosest_heap_multiset(vector<vector<int>>& points, int K) {
        multiset<vector<int>, compare_less> ms;
        for (auto &point : points) {
            ms.insert(point);
        }
        vector<vector<int>> ans;
        copy_n(ms.begin(), K, back_inserter(ans));
        return ans;
    }
    
    vector<vector<int>> kClosest_quickselection(vector<vector<int>>& points, int K) {
        int l = 0, r = points.size() - 1;
        while (l<=r) {
            auto pivot = partition(points, l, r);
            if (pivot == K) {
                break;
            }
            if (pivot > K) {
                r = pivot - 1;
            }
            else {
                l = pivot + 1;
            }
        }
        return vector<vector<int>>(points.begin(), points.begin()+K);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        //return kClosest_sort(points, K);
        //return kClosest_heap_priorityqueue(points, K);
        //return kClosest_heap_multiset(points, K);
        return kClosest_quickselection(points, K);
    }
private:
    int partition(vector<vector<int>>& points, int l, int r) {
        if (l==r) return l;
        int randpivot = rand() % (r-l) + l;
        swap(points[randpivot], points[r]);
        int idx = l;
        for (int i=l; i<r; ++i) {
            if ((points[i][0] * points[i][0]) + (points[i][1] * points[i][1])
               < (points[r][0] * points[r][0]) + (points[r][1] * points[r][1])) {
                swap(points[i], points[idx++]);
            }
        }
        swap(points[idx], points[r]);
        
        return idx;
    }
    
    struct compare_less {
        bool operator()(vector<int>& a, vector<int>& b) {
            return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
        }
        bool operator()(const vector<int>& p, const vector<int>& q) const {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        }
    };
    
    struct compare_greater {
        bool operator()(vector<int>& a, vector<int>& b) {
            return (a[0] * a[0] + a[1] * a[1]) > (b[0] * b[0] + b[1] * b[1]);
        }  
    };
};

int main()
{
    auto input1 = vector<vector<int>>();
    input1.push_back(vector<int> {1, 3});
    input1.push_back(vector<int> {-2, 2});
    auto ans1 = vector<vector<int>>();
    ans1.push_back(vector<int> {-2, 2});
    assert(Solution().kClosest(
        input1, 1
    ) == (ans1));
    return 0;
}
