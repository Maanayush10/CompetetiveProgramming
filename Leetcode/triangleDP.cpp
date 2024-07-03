/*

120. Triangle
Solved
Medium
Topics
Companies
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104

*/

class Solution {
public:
    int f(int i, int j, int size, vector<vector<int>>& triangle,
          vector<vector<int>>& dp) {
        if (i == size - 1) {
            return triangle[i][j];
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int d = triangle[i][j] +
                f(i + 1, j, size, triangle, dp); // next row same col
        int dg = triangle[i][j] +
                 f(i + 1, j + 1, size, triangle, dp); // next row next col

        return dp[i][j] = min(d, dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),
                               vector<int>(triangle.size(), -1));
        // return f(0, 0, triangle.size(), triangle, dp);
        int n= triangle.size();
        for(int j=0; j<n; j++)
        {
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2; i>=0; i--)
        {
            for(int j=i; j>=0; j--)
            {
                int d= triangle[i][j]+dp[i+1][j]; 
                int dg= triangle[i][j]+dp[i+1][j+1]; 
                dp[i][j]= min(d, dg);
            }
        }
        return dp[0][0];
    }
};
