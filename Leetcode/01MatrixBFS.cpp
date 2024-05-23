/*

542. 01 Matrix
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.

*/

class Solution {
public:
    /*
    I call it reverse Osmosis method (RO)
    Approach:  What we do here is, in the result matrix we add first all the
    zeroes. Then  from each zero we check 4 directionally if we have a INT_MAX
    or not. if yes, update INT_MAX to the current entry of the cell +1

    */

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        // Initialize the queue with all '0' cells and set their distances to 0
        // in result
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Direction vectors for moving in the 4 cardinal directions
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // Perform BFS from all initial '0' cells
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            // Check all 4 possible directions
            for (int i = 0; i < 4; i++) {
                int mrow = row + delRow[i];
                int mcol = col + delCol[i];

                // If the new position is within bounds and not yet processed
                if (mrow >= 0 && mrow < m && mcol >= 0 && mcol < n) {
                    if (result[mrow][mcol] == INT_MAX) {
                        result[mrow][mcol] = result[row][col] + 1;
                        q.push({mrow, mcol});
                    }
                }
            }
        }

        return result;
    }
};
