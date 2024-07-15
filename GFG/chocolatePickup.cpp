/*

Chocolates Pickup
You are given an n rows and m cols matrix grid representing a field of chocolates where grid[i][j] represents the number of chocolates that you can collect from the (i, j) cell.

You have two robots that can collect chocolates for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of chocolates collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all chocolates, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the chocolates.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
Example:

Input:
n = 4, m = 3
grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output:
24
Explanation:
Path of robot #1 and #2 are described in color green and blue respectively. Chocolates taken by Robot #1, (3 + 2 + 5 + 2) = 12. Chocolates taken by Robot #2, (1 + 5 + 5 + 1) = 12. Total of Chocolates: 12 + 12 = 24.
Expected Time Complexity: O(n * m * m)
Expected Space Complexity: O(n * m * m)

Constraint:
2 <= n, m < = 70
0 <= grid[i][j] <= 100

*/


class Solution {
public:
    int f(int row, int col1, int col2, int rowSize, int colSize, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if (row == rowSize - 1) {
            if (col1 == col2) {
                return grid[row][col1];
            } else {
                return grid[row][col1] + grid[row][col2];
            }
        }
        if(dp[row][col1][col2]!=-1){return dp[row][col1][col2];}

        int maxChoco = 0;
        for (int newCol1 = col1 - 1; newCol1 <= col1 + 1; newCol1++) {
            for (int newCol2 = col2 - 1; newCol2 <= col2 + 1; newCol2++) {
                // Changed '> 0' to '>= 0' to correctly handle boundary conditions
                if (newCol1 >= 0 && newCol1 < colSize && newCol2 >= 0 && newCol2 < colSize) {
                    int currentChoco;
                    if (col1 == col2) {
                        currentChoco = grid[row][col1] + f(row + 1, newCol1, newCol2, rowSize, colSize, grid, dp);
                    } else {
                        currentChoco = grid[row][col1] + grid[row][col2] + f(row + 1, newCol1, newCol2, rowSize, colSize, grid, dp);
                    }
                    maxChoco = max(maxChoco, currentChoco);
                }
            }
        }
        return dp[row][col1][col2]= maxChoco;
    }

    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return f(0, 0, m - 1, n, m, grid, dp);
    }
};
