/*

733. Flood Fill
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

 

Example 1:


Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation: The starting pixel is already colored 0, so no changes are made to the image.
 

Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n

*/

//shoutout to Raj Vikramaditya
class Solution {
private:
    void dfs(int sr, int sc, vector<vector<int>>& image,
             vector<vector<int>>& ans, int newColor, int oldColor, int delRow[],
             int delCol[]) {

        ans[sr][sc] = newColor;
        for (int i = 0; i < 4; i++) {
            int mrow = sr + delRow[i];
            int mcol = sc + delCol[i];

            if (mrow >= 0 && mrow < image.size() && mcol >= 0 &&
                mcol < image[0].size() && image[mrow][mcol] == oldColor &&
                ans[mrow][mcol] != newColor) {
                dfs(mrow, mcol, image, ans, newColor, oldColor, delRow, delCol);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        vector<vector<int>> result = image;
        int initColor = image[sr][sc];
        int delCol[] = {0, 1, 0 ,- 1};
        int delRow[] = {-1, 0, 1, 0};
        dfs(sr, sc, image, result, color, initColor, delRow, delCol);
        return result;
    }
};
