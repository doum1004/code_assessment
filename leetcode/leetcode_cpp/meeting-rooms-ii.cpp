#include <iostream>
#include <cassert>
#include "../utils.h"

#include <vector>
#include <queue>
#include <map>

using namespace std;

/**
https://leetcode.com/problems/meeting-rooms-ii/

// Soltuion1. Sort and bruteforce
// time: (n^2). nlogn(sort) + n*n(compare)
// space: o(1)

1. iterate i: 0 to n. iterate j: 0 to i-1.
2. intervals[i][0] < intervals[j][1] count++
1-5, 2-3, 2-4, 7-15
 0    1    2    0
i=0, 0
i=1, 3<5. 1
i=2, 3<5, 2<3. 2
i=3, 0
return 2+1

// Soltuion2. Sort and min-heap. (Improve solution1)
// https://leetcode.com/problems/meeting-rooms-ii/discuss/67989/Concise-C%2B%2B-Solution-with-min_heap-sort-greedy
Use min-heap to get the earliest availiable time. (only one to keep the largest size)
// time: o(nlogm) sort + (iterate(n) * min-heap add/remove(logm)) m(heap size)
// space: o(m) heap size

1-5, 2-3, 2-4, 7-15

i=0 minheap: 5
i=1 minheap: 3 5
i=2 minheap: 3 4 5
i=3 minheap: 4 5 15

// Soltuion3. orderedmap to count start(++) and end(--)
// https://leetcode.com/problems/meeting-rooms-ii/discuss/67866/C%2B%2B-solution-using-a-map.-total-11-lines
Orderedmap, will sort values. in sorted values, start will occupy room(+1), end will leave room(-1). then we could see how many room they use.
// time: o(nlogn). ordered map add
// space: o(n): map size

1-5, 2-3, 2-4, 7-15
-> 1(+1), 2(+1+1), 3(-1), 4(-1), 5(-1), 7(+1), 15(-1)
max occupied room at 2

*/

class Solution {
public:
    int minMeetingRooms_sort_bruteforce(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) return intervals.size();
        
        sort(intervals.begin(), intervals.end(), [&](auto &a, auto &b) {
           return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0]; 
        });
        
        
        int max_overrap = 0;
        for (int i=0; i<intervals.size(); ++i) {
            int overrap = 0;
            for (int j=0; j<i; ++j) {
                if (intervals[i][0] < intervals[j][1]) overrap++;
            }
            max_overrap = max(max_overrap, overrap);
        }
        
        return max_overrap + 1;
    }
    
    int minMeetingRooms_sort_minheap(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) return intervals.size();
        
        sort(intervals.begin(), intervals.end(), [&](auto &a, auto &b) {
            return a[1] == b[1] ? a[1] < b[1] : a[0] < b[0];
        });
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        
        for (auto &v:intervals) {
            if (!min_heap.empty() && min_heap.top() <= v[0]) min_heap.pop();
            min_heap.push(v[1]);
        }
        
        return min_heap.size();
    }
    
    int minMeetingRooms_orderedmap(vector<vector<int>>& intervals) {
        map<int, int> m;
        for (auto &v:intervals) {
            m[v[0]]++;
            m[v[1]]--;
        }
        
        int room=0;
        int sum=0;
        for (auto &v:m) {
            sum += v.second;
            room = max(room, sum);
        }
        
        return room;
    }
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        //return minMeetingRooms_sort_bruteforce(intervals);
        //return minMeetingRooms_sort_minheap(intervals);
        return minMeetingRooms_orderedmap(intervals);
    }
};

int main()
{
    auto input1 = vector<vector<int>> {{0, 30},{5, 10},{15, 20}};
    assert(Solution().minMeetingRooms(input1)
        == 2);
    return 0;
}