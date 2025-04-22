#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// 994. Rotting Oranges
// It is the same as p1, do BFS and search in 4 directions. Only search by the timing that the nodes are pushed into the queue.

class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            int ans = 0;
            int m = grid.size();
            int n = grid[0].size();
            vector<pair<int, int>> d = {{1, 0},{-1, 0},{0, -1},{0, 1}};
            queue<pair<int, int>> q;
            int cnt = 0;
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][j] == 2) q.push({i,j});
                    if(grid[i][j] == 1) cnt++;
                }
            }
            if(cnt == 0) return 0;
            if(q.empty()) return -1;
            while (!q.empty()) {
                int size = q.size();
                while (size--) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (auto [dx, dy] : d) {
                        int i = x + dx;
                        int j = y + dy;
                        if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1) {
                            grid[i][j] = 2;
                            cnt--;
                            q.push({i, j});
                        }
                    }
                }
                ans++;
            }
            if(cnt == 0) return ans - 1;
            else return -1;
        }
    };