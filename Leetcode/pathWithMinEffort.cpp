/*

1631. Path With Minimum Effort
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

Example 1:



Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
Example 2:



Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
Example 3:


Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
 

Constraints:

rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106

*/
/*
shoutout to raj vikramaditya
approach
1) initialise a distance matrix, and a priority q as we use dijikstra's algorithm(min heap)
2) traverse 4 directionally for each cell
3) if the cell that is being stored in the pq is the destination return the currenrEffort calculated. 
4)The currentEffort only stores the max abs difference found in a given path
5) if the max currentEffort is less than the one stored in the distance matrix, the update the distance matrix, then push the cell(distance, coordinates)
*/
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<>> q;
        q.push({0, {0, 0}});
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        distance[0][0] = 0;
        while (!q.empty()) {
            pair<int, int> cell = q.top().second;
            int currentEffort = q.top().first;
            int oldRow = cell.first;
            int oldCol = cell.second;
            q.pop();
            if(oldRow==rows-1 && oldCol==cols-1)
            {
                return currentEffort;
            }
            for (int i = 0; i < 4; i++) {
                int mrow = oldRow + delRow[i];
                int mcol = oldCol + delCol[i];
                if(mrow>=0 && mrow< rows && mcol>=0 && mcol <cols)
                {
                    int newEffort= max(currentEffort, abs(heights[mrow][mcol]- heights[oldRow][oldCol]));
                    if(newEffort < distance[mrow][mcol])
                    {
                        distance[mrow][mcol]= newEffort;
                        q.push({newEffort, {mrow, mcol}});
                    }
                }
            }
        }
        return 0;
    }
};
