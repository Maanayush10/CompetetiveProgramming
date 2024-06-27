/*

1319. Number of Operations to Make Network Connected

There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

 

Example 1:


Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
Example 2:


Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.
 

Constraints:

1 <= n <= 105
1 <= connections.length <= min(n * (n - 1) / 2, 105)
connections[i].length == 2
0 <= ai, bi < n
ai != bi
There are no repeated connections.
No two computers are connected by more than one cable.

*/

/*
Approach:
1) Make a disjoint set datastruture
2) calculate number of components (count, here)
3) also calculate extra edges

check if two nodes have same parent, if not then perform union accordingly, if yes, that means we have encountered a cycle or an edge that is extra.

the important note here is you can only make connections by removing and using the already present connected cables, so if you don't
have sufficient extra edges, you will not be able to connect the components

4) check if you extra edges >= number of components, if yes, return number of components -1 (why ? to connect 2 components you need 1 edge)
*/

class DisjointSet {

    vector<int> rank, parent;
public:
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int count = 0, extraEdges = 0;
        for (int i = 0; i < connections.size(); i++) {
            int from = connections[i][0];
            int to = connections[i][1];

            if (ds.findPar(from) != ds.findPar(to)) {
                ds.unionByRank(from, to);
            } else {
                extraEdges++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i) {
                count++;
            }
        }
        return count - 1 <= extraEdges ? count - 1 : -1;
    }
};
