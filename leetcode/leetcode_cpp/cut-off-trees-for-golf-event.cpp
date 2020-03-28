#include <iostream>
#include <cassert>

#include <vector>
#include <queue>

using namespace std;

/**
https://leetcode.com/problems/cut-off-trees-for-golf-event/submissions/

- Solution1. Sort and BSF to find shortest next paths
- time: o((m*n)^2)
- space: o(m*n). visited
Todo->optimization

- Solution2. A* algorithm(like dijkstra) use heap with cost(distance)
Todo !!!!

*/

class Solution {
public:
    int offset[5] = {0, 1, 0, -1, 0};
    int bsf(vector<vector<int>>& forest, int s_r, int s_c, int t_r, int t_c) {
        if (s_r == t_r && s_c == t_c) return 0;
        int m = forest.size(), n = forest[0].size();
        
        queue<pair<int,int>> q;
        q.push({s_r, s_c});
        
        vector<vector<int>> v(m, vector<int>(n, 0));
        v[s_r][s_c] = 1;
        
        int step = 0;
        while (!q.empty()) {
            int qn = q.size();
            step++;
            for (int i=0; i<qn; ++i) {
                auto r = q.front().first, c = q.front().second;
                q.pop();
                
                for (int j=0; j<=3; ++j) {
                    auto new_r = r + offset[j], new_c = c + offset[j+1];
                    if (new_r == t_r && new_c == t_c) return step;
                    if (new_r >= 0 && new_c >= 0 && new_r < m && new_c < n && !v[new_r][new_c] && forest[new_r][new_c] > 0) {
                        v[new_r][new_c] = 1;
                        q.push({new_r,new_c});
                    }
                }
            }
        }
        return -1;
    }
    
    int cutOffTree_sort_bsf(vector<vector<int>>& forest) {
        if (forest.empty() || forest[0].empty()) return -1;
        int m = forest.size(), n = forest[0].size();
        //sort
        vector<tuple<int,int,int>> trees;
        for (int r=0; r<m; ++r) {
            for (int c=0; c<n; ++c) {
                if (forest[r][c] > 1) trees.push_back({forest[r][c], r, c});
            }
        }
        sort(trees.begin(), trees.end());
        
        int res = 0;
        int s_r = 0, s_c = 0;
        for (auto &tree:trees) {
            int t_r = get<1>(tree);
            int t_c = get<2>(tree);
            
            int result = bsf(forest, s_r, s_c, t_r, t_c);
            //cout << result << ":" << t_r << "," << t_c << endl;
            if (result == -1) return -1;
            res += result;
            
            s_r = t_r;
            s_c = t_c;
        }
        return res;
    }
    
    int cutOffTree(vector<vector<int>>& forest) {
        return cutOffTree_sort_bsf(forest);
    }
};

int main()
{
    auto input1 = vector<vector<int>> {{1,2,3}, {0,0,4}, {7,6,5}};
    assert(Solution().cutOffTree(input1) == (6));
    
    auto input2 = vector<vector<int>> {{1,2,3}, {0,0,0}, {7,6,5}};
    assert(Solution().cutOffTree(input2) == (-1));
    
    return 0;
}