/*

827. Making A Large Island
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.

*/

class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }
    void UnionBySize(int u, int v) {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if (ulp_u == ulp_v) // they belong to the same component
        {
            return;
        }
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else if (size[ulp_v] < size[ulp_u]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

/*

Approach
1) two steps using unionBySize
2) step-1 --> connect all 1s for each component
2) for all zeros find the nearest 1 4-directionally and push its parent to the set. we are using set to prevent overlapping like in below case:
        1 1 1
        1 0 1
        1 1 1    ---> here 0 is surrounded by 4 ones which are essentially the same component, 
                      so to avoid adding the size of the same component 4 times, we use set
3) find the size of each parent in the set in the current iteration, add 1 for the current cell, and check it again max variable mx.
4) Deal with one edge case where all entries are 1. so the second step will ignore the entire component, and give max size as 0.
for that go thru the entire grid and check for each 1's ultimate parent and then check it against max.

*/

//shoutout to striver
class Solution {
private:
    bool isValid(int row, int col, int n) {
        if (row >= 0 && row < n && col >= 0 && col < n) {
            return true;
        }
        return false;
    }

public:
    // calculated nodeNum by formula ==> row* size + col
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        int delRow[] = { -1, 0, +1, 0 };
        int delCol[] = { 0, 1, 0, -1 };
        // step1: connecting components (all 1s together)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;

                for (int ind = 0; ind < 4; ind++) {
                    int newr = i + delRow[ind];
                    int newc = j + delCol[ind];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        int nodeNum = i * n + j;
                        int adjacentNodeNum = newr * n + newc;
                        ds.UnionBySize(nodeNum, adjacentNodeNum);
                    }
                }
            }
        }
        // step-2  try replacing all zeros with 1 (one by one) and find largest component
        int mx = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1)
                    continue;
                set<int> CompParents;
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + delRow[ind];
                    int newc = col + delCol[ind];
                    if (isValid(newr, newc, n)) {
                        if (grid[newr][newc]) {
                            CompParents.insert(ds.findPar(newr * n + newc));
                        }
                    }
                }
                int sizeTotal = 0;
                for (auto it : CompParents) {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal+1);
            }
        }
        for(int cellNo=0; cellNo< n*n ; cellNo++)
        {
            mx= max(mx, ds.size[ds.findPar(cellNo)]);
        }
        return mx;
    }
};
