/*

Find the number of islands

Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is either surrounded by water or boundary of grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
Example 2:

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0 
There are two islands :- one is colored in blue 
and other in orange.
Your Task:
You don't need to read or print anything. Your task is to complete the function numIslands() which takes the grid as an input parameter and returns the total number of islands.

Expected Time Complexity: O(n*m)
Expected Space Complexity: O(n*m)

Constraints:
1 ≤ n, m ≤ 500

*/

/*

approach:
using dfs: keep a visited matrix (here in code called the result matrix), and mark all zeroes. Then everytime you encounter '1' in the original grid matrix
recursively find all the 1s in 8 direction space. Note have made a visited matrix to make sure that the dfs func is not called at the visited points. Everytime
i return from the dfs func to main func i increment the count as all the current island associated with the current '1' has been found.

*/
class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& result, int delRow[], int delCol[])
    {
        int n= grid.size();
        int m= grid[0].size();
        result[row][col]=1;
        for(int i=0; i<8; i++)
        {
            int mrow=row+delRow[i];
            int mcol= col+delCol[i];
            if(mrow>=0 && mrow<n && mcol>=0 && mcol<m)
            {
                if(grid[mrow][mcol]=='1' && result[mrow][mcol]!=1)
                {
                    dfs(mrow, mcol, grid, result, delRow, delCol);
                }
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n= grid.size();
        int m= grid[0].size();
        
        vector<vector<int>>result(n, vector<int>(m, -1));
        int delRow[]={-1, 1, 0, 0, -1, -1, 1, 1};
        int delCol[]={0, 0, -1, 1, -1, 1, -1, 1};
        int count=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='0')
                {
                    result[i][j]=0;
                }
                if(grid[i][j]=='1' && result[i][j]!=1)
                {
                    dfs(i, j, grid, result, delRow, delCol);
                    count++;
                }
            }
        }
        return count;
    }
};
