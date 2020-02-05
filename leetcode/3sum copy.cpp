#include <iostream>
#include <cassert>
#include "../utils.h"

#include <vector>
#include <queue>
#include <map>

using namespace std;

/**
https://leetcode.com/problems/meeting-rooms-ii/

// Solution1. sort and brute force to get available room, if not add new room with time
// time: o(n^2) : iterate time and rooms
// space: o(n) : room(n)

// Solution2. Improve solution1. not to iterate rooms to find available
// Use min-heap to get the earlist avaiable time. if top isn't available for it, add new room.
// https://leetcode.com/problems/meeting-rooms-ii/discuss/67989/Concise-C%2B%2B-Solution-with-min_heap-sort-greedy
// time: o(nlogn)
// space: o(n) : room(n) + min-heap(n)

// Solution3. map(ordered) counting start(+1) and end(-1)
// https://leetcode.com/problems/meeting-rooms-ii/discuss/67866/C%2B%2B-solution-using-a-map.-total-11-lines
// time: o(nlogn)
// space: o(n) : map

*/
class Solution {
public:
    int minMeetingRooms_bruteforce(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) return intervals.size();
        
        sort(intervals.begin(), intervals.end(), [&](auto &l, auto &r){
            return l[0] == r[0] ? l[1] < r[1] : l[0] < r[0];
        });
        
        vector<vector<pair<int,int>>> rooms;
        
        int nbroom = intervals.size();
        for (int i=0; i<intervals.size(); ++i) {
            auto l1 = intervals[i][0];
            auto r1 = intervals[i][1];
            if (rooms.size() == 0) {
                rooms.push_back(vector<pair<int,int>> {{l1,r1}});
            }
            else {
                auto foundspace = true;
                for (auto &room:rooms) {
                    foundspace = true;
                    for (auto &time:room) {
                        auto l2 = time.first;
                        auto r2 = time.second;
                        
                        foundspace &= ((l1 < l2 && r1 <= l2) || (l1 >= r2 && r1 > r2));
                    }
                    if (foundspace) {
                        room.push_back({l1,r1});
                        break;
                    }
                }
                
                if (!foundspace) {
                    rooms.push_back(vector<pair<int,int>> {{l1,r1}});
                }
            }
        }
        return rooms.size();
    }
    
    int minMeetingRooms_heap(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) return intervals.size();
        
        sort(intervals.begin(), intervals.end(), [&](auto &l, auto &r){
            return l[0] == r[0] ? l[1] < r[1] : l[0] < r[0];
        });
        
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (auto &v:intervals) {
            auto l = v[0];
            auto r = v[1];
            if (!min_heap.empty() && min_heap.top() <= l) min_heap.pop();
            min_heap.push(r);
        }
        return min_heap.size();
    }
    
    int minMeetingRooms_map(vector<vector<int>>& intervals) {
        map<int,int> counter;
        for (auto &interval:intervals) {
            counter[interval[0]]++;
            counter[interval[1]]--;
        }
        
        int room = 0;
        int cur = 0;
        for (auto &v:counter) {
            cur += v.second;
            room = max(room, cur);
        }
        
        return room;
    }
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        //return minMeetingRooms_bruteforce(intervals);
        //return minMeetingRooms_heap(intervals);
        return minMeetingRooms_map(intervals);
    }
};

int main()
{
    auto input1 = vector<vector<int>> {{0, 30},{5, 10},{15, 20}};
    assert(Solution().minMeetingRooms(input1)
        == 2);
    return 0;
}