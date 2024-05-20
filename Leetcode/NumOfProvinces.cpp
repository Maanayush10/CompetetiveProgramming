/*

547. Number of Provinces
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:

Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2

Example 2:

Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3

 

Constraints:

    1 <= n <= 200
    n == isConnected.length
    n == isConnected[i].length
    isConnected[i][j] is 1 or 0.
    isConnected[i][i] == 1
    isConnected[i][j] == isConnected[j][i]



*/

class Solution {
private:
    void dfs(vector<int> adj[], int node, int vis[])
    {
        vis[node]=1;
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                dfs(adj, it, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V= isConnected.size();
        int vis[V]; // Declare the array outside the function
        memset(vis, 0, sizeof(vis));
        // vector<int>vis;
        int count=0;
        vector<int> adj[V];
        //making adjancency list for convenience
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
            {
                if(isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        //using dfs to find connected compenents
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
            {
                //each time a new call made, that means news starting point
                count++;
                dfs(adj, i, vis);
            }
        }
        return count;
    }
};
