/*

1020. Number of Enclaves
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 0 or 1.

*/
//same approach as surrounding regions problem on leetcode
/*

Approach: check if any '1' on the boundary, if yes recursively travel to all adjacent '1' from there using dfs and find all the '1'of the chain. 
These '1' are not completely surrounded by 0 so they wont be captured. The resultant matrix is initialised with -1. In the approach below we find all 1s 
that are connected to the 1s on the boundary, and mark them 1, and we count the remaining -1 counted and the count is returned.

*/
class Solution {
private:
    void check(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& result, int delRow[], int delCol[])
    {
        int m= grid.size();
        int n= grid[0].size();

        for(int i=0; i<4; i++)
        {
            int mrow= row + delRow[i];
            int mcol= col+ delCol[i];

            if(mrow>=0 && mrow<m && mcol<n && mcol>=0)
            {
                if(grid[mrow][mcol]==1 && result[mrow][mcol]!=1)
                {
                    result[mrow][mcol]= 1;
                    check(mrow, mcol, grid, result, delRow, delCol);
                }

            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<int>> result(m, vector<int>(n, -1));
        int delRow[]={-1, 0, 1, 0};
        int delCol[]={0, 1, 0, -1};
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==0)
                {
                    result[i][j]=0;
                }
                else if(grid[i][j]==1 && ((i==0||i==m-1)||(j==0|| j==n-1)))
                {
                    result[i][j]=1;
                    check(i, j, grid, result, delRow, delCol);

                }
            }
        }
        int count=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(result[i][j]==-1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};
