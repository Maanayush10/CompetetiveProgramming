/*

947. Most Stones Removed with Same Row or Column
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

 

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
Example 3:

Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.
 

Constraints:

1 <= stones.length <= 1000
0 <= xi, yi <= 104
No two stones are at the same coordinate point.

*/

//solved myself

/*
Approach:
1) Create disjoint set data-structure.
2) Trace out all the coordinates for each stone in vector<pair<int, pair<int, int>>> stoneWithCood datastructure {stone, {x, y}}.
3) For all stones having same row and column create an edge between them and create an edges list.
4) Find number of components. For each component, we will keep the parent and remove everything.
5) Hence return (Number of stones - Number of ultimate parents (which is same as number of components)).

make a diagram to understand the problem and find observations.
*/
class DisjointSet {
public:
    vector<int> rank, parent;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if (ulp_u == ulp_v)
            return; // they belong to the same component
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int numOfStones = stones.size();
        vector<pair<int, pair<int, int>>> stoneWithCood;
        vector<vector<int>> edges;
        for (int i = 0; i < numOfStones; i++) {
            stoneWithCood.push_back({i, {stones[i][0], stones[i][1]}});
        }
        for (int i = 0; i < stoneWithCood.size(); i++) {
            int node = stoneWithCood[i].first;
            int x = stoneWithCood[i].second.first;
            int y = stoneWithCood[i].second.second;

            for (int j = i + 1; j < stoneWithCood.size(); j++) {
                int nodeTemp = stoneWithCood[j].first;
                int xTemp = stoneWithCood[j].second.first;
                int yTemp = stoneWithCood[j].second.second;

                if (x == xTemp || y == yTemp) {
                    edges.push_back({node, nodeTemp});
                }
            }
        }
        DisjointSet dis(numOfStones - 1);
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            if (dis.findPar(u) != dis.findPar(v)) {
                dis.unionByRank(u, v);
            }
        }
        int count = 0;
        for (int i = 0; i < numOfStones; i++) {
            if (dis.parent[i] == i) {
                count++;
            }
        }
        return numOfStones - count;
    }
};
