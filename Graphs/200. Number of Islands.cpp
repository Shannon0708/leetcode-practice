#include<vector>
#include<stack>
#include<queue>

using namespace std;

class Solution_DFS {
public:
    int numIslands(vector<vector<char>>& grid) {
        int NUM = 0;

        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == '1') {
                    dfs_recursive(grid, i, j);
                    ++NUM;
                }
            }
        }

        return NUM;
    }

    void dfs_recursive(vector<vector<char>>& grid, int i, int j) {
        if( i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0')
            return;
        grid[i][j] = '0';

        dfs_recursive(grid, i - 1, j);    // left
        dfs_recursive(grid, i + 1, j);    // right
        dfs_recursive(grid, i, j + 1);    // down
        dfs_recursive(grid, i, j - 1);    // up
    }
};

//把 DFS 寫成 stack 版
class Solution_DFS_Iterative {
public:
        int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        stack<pair<int, int>> stk;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        stack<pair<int, int>> stk;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        stk.push({i, j});
        while (!stk.empty()) {
            auto [x, y] = stk.top();
            // x = stk.top().first;
            // y = stk.top().second;
            stk.pop();
            
            for(auto [dx, dy] : directions) {
                if (x+dx < 0 || y+dy < 0 || x+dx >= m || y+dy >= n || grid[x+dx][y+dy] == '0') continue;
                stk.push({x + dx, y + dy});
                grid[x+dx][y+dy] = '0';
            }
        }
    }
};

class Solution_BFS {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int count = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    bfs(grid, i, j);
                }
            }
        }
        return count;
    }

    void bfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        q.push({i, j});
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for(auto [dx, dy] : directions) {
                if (x+dx < 0 || y+dy < 0 || x+dx >= m || y+dy >= n || grid[x+dx][y+dy] == '0') continue;
                q.push({x + dx, y + dy});
                grid[x+dx][y+dy] = '0';
            }
        }
    }
};