/*

Shortest path in Undirected Graph
You are given an Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

Example1:

Input:
n = 9, m= 10
edges=[[0,1],[0,3],[3,4],[4,5],[5,6],[1,2],[2,6],[6,7],[7,8],[6,8]] 
src=0
Output:
0 1 2 1 2 3 3 4 4
Explanation:
Example2:

Input:
n = 4, m= 4
edges=[[0,0],[1,1],[1,3],[3,0]] 
src=3
Output:
1 1 -1 0
Explanation:
Your Task:
You don't need to print or input anything. Complete the function shortest path() which takes a 2d vector or array of edges representing the edges of an undirected graph with unit weight, an integer n as the number of nodes, an integer m as a number of edges and an integer src as the input parameters and returns an integer array or vector, denoting the vector of distance from src to all nodes.

Constraint:
1<=n,m<=10000
0<=edges[i][j]<=n-1

Expected Time Complexity: O(N + E), where N is the number of nodes and E is the edges
Expected Space Complexity: O(N)

*/
//shoutout to striver
/*
Algorithm:
Made an adjacency list of the edges matrix
initialise a queue<pair<int, int>> and push src node with 0 distance, a distance array of N nodes, all having INT_MAX entries
while(!q.empty)
{
  the first entry is the node, and second is the distance
  check for each node in the adjacency list if their current distance is less than their respective entry in the distance array or not
  if yes( push the current node and distance to queue and update the distance matrix)
}
if the their are any INT_MAX entries left in the distance array, make it -1
*/
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> distance(N, INT_MAX);
        queue<pair<int, int>>q;
        vector<int>adj[N];
        for(int i=0; i<M; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        q.push({src, 0});
        distance[src]=0;
        while(!q.empty())
        {
            int node= q.front().first;
            int prevDist= q.front().second;
            q.pop();
            for(auto it: adj[node])
            {
                int dist= prevDist+1;
                if(dist<distance[it])
                {
                    distance[it]= dist;
                    q.push({it, dist});
                }
            }
        }
        
        for(int i=0; i<distance.size(); i++)
        {
            if(distance[i]== INT_MAX)
            {
                distance[i]= -1;
            }
        }
        return distance;
    }
};
