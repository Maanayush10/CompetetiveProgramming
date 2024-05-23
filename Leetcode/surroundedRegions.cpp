/*

130. Surrounded Regions
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

 

Example 1:


Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.
Example 2:

Input: board = [["X"]]
Output: [["X"]]
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.

*/
//solved this on my own, hell yeah, shoutout to me.
/*

Approach: check if any 'O' on the boundary, if yes recursively travel to all adjacent 'o' from there using dfs and find all the 'O'of the chain. 
These 'O' are not completely surrounded by X so they wont be captured. Rest 'O' will be captured.

*/
class Solution {
private:
    void check(int row, int col, vector<vector<char>>& board,
               vector<vector<char>>& result, int delRow[], int delCol[]) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < 4; i++) {
            int mrow = row + delRow[i];
            int mcol = col + delCol[i];
            if (mrow >= 0 && mrow < m && mcol >= 0 && mcol < n) {
                if (board[mrow][mcol] == 'O' && result[mrow][mcol] != 'O') {
                    result[mrow][mcol] = 'O';
                    check(mrow, mcol, board, result, delRow, delCol);
                }
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<char>> result(m, vector<char>(n, 'C'));
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') {
                    result[i][j] = 'X';
                } else if (board[i][j] == 'O' &&
                           ((i == 0 || i == m - 1) || (j == 0 || j == n - 1))) {
                    result[i][j] = 'O';
                    check(i, j, board, result, delRow,
                          delCol); // send all the boundary "O" to a q
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (result[i][j] == 'C') {
                    result[i][j] = 'X';
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = result[i][j];
            }
        }
    }
};
