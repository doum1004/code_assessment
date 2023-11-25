/*
https://leetcode.com/problems/snakes-and-ladders

Soltuion1. BSF
time: o(n^2) o(v+e) = v(7n^2)
space: o(n^2)

1. Build cells to contain actual number with board row, col to track easier
2. make visit list to store marking it is visited and many steps
3. BSF queue to store next visit
4. From queue pop, find next move + (1 ~ min(6, n^2))
5. If it has ladder, put it as dst else keep the same as next
6. check visit list, if not keep the step and push into queue to next iteration
*/
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {

        // list to store board row, col in value
        // ex) n = 5
        // cells[1] = {4, 0}
        // cells[2] = {4, 1}
        // cells[5] = {4, 4}
        // cells[6] = {3, 4}
        // cells[7] = {3, 3}

        int n = board.size();
        vector<pair<int,int>> cells(n*n+1);
        int num = 1;
        vector<int> cols(n);
        // for (int i=0; i<n; ++i);
        //     cols[i] = i;
        iota(cols.begin(), cols.end(), 0);
        for (int r=n-1; r>=0; r--) {
            for (int c : cols)
                cells[num++] = {r, c};
            reverse(cols.begin(), cols.end());
        }

        vector<int> visit(n*n+1, -1);
        visit[1] = 0;
        queue<int> q;
        q.push(1);

        while (!q.empty()) {
            int qSize = q.size();
            for (int i=0; i<qSize; ++i)
            {
                int cur = q.front();
                q.pop();
                int maxNext = min(cur+6, n*n);
                for (int next = cur+1; next <= maxNext; ++next) {
                    auto [row, col] = cells[next];
                    int dest = board[row][col] != -1 ? board[row][col] : next;
                    if (visit[dest] == -1) {
                        visit[dest] = visit[cur] + 1;
                        q.push(dest);
                    }
                }
            }
        }

        return visit[n*n];
    }
};