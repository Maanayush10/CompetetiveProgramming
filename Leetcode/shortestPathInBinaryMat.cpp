/*

1091. Shortest Path in Binary Matrix
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

 

Example 1:


Input: grid = [[0,1],[1,0]]
Output: 2
Example 2:


Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1

*/


/*
Approach: 
1) if grid[0][0] or grid[n-1][n-1] are 1 then return -1 directly.
2) initialise a visited array (n*n) and a queue<pair<pair<int, int>, int>> which will store my coordinates and distance travelled till now.
3) traverse 8 directionaly using delRow and delCol and keep pushing the the coordinates and distances to the queue.
4) all the adjacent tiles are traversed using dfs and the minDist variable stores the path length which is minimum.
*/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int start = 0, end = n - 1;
        if (grid[start][start] == 1 || grid[end][end] == 1) {
            return -1;
        }
        vector<vector<int>> visited(n, vector<int>(n, 0));
        int delRow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int delCol[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        queue<pair<pair<int, int>, int>> q;
        q.push({{start, start}, 1});
        int minDist = INT_MAX;
        while (!q.empty()) {
            pair<int, int> cell = q.front().first;
            int dist = q.front().second;
            int oldRow = cell.first;
            int oldCol = cell.second;
            q.pop();
            if (oldRow == end && oldCol == end) {
                minDist = min(minDist, dist);
            }
            for (int i = 0; i < 8; i++) {
                int mrow = oldRow + delRow[i];
                int mcol = oldCol + delCol[i];

                if (mrow >= 0 && mrow <= end && mcol >= 0 && mcol <= end &&
                    !visited[mrow][mcol]) {
                    if (grid[mrow][mcol] == 0) {
                        visited[mrow][mcol] = 1;
                        q.push({{mrow, mcol}, dist + 1});
                    }
                }
            }
        }
        if (minDist == INT_MAX)
            return -1;
        return minDist;
    }
};
