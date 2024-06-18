/*

Distance from the Source (Bellman-Ford Algorithm)
Given a weighted and directed graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S. If a vertices can't be reach from the S then mark the distance as 10^8. Note: If the Graph contains a negative cycle then return an array consisting of only -1.

Example 1:

Input:

E = [[0,1,9]]
S = 0
Output:
0 9
Explanation:
Shortest distance of all nodes from
source is printed.
Example 2:

Input:

E = [[0,1,5],[1,0,3],[1,2,-1],[2,0,1]]
S = 2
Output:
1 6 0
Explanation:
For nodes 2 to 0, we can follow the path-
2-0. This has a distance of 1.
For nodes 2 to 1, we cam follow the path-
2-0-1, which has a distance of 1+5 = 6,
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function bellman_ford( ) which takes a number of vertices V and an E-sized list of lists of three integers where the three integers are u,v, and w; denoting there's an edge from u to v, which has a weight of w and source node S as input parameters and returns a list of integers where the ith integer denotes the distance of an ith node from the source node.

If some node isn't possible to visit, then its distance should be 100000000(1e8). Also, If the Graph contains a negative cycle then return an array consisting of a single -1.

 

Expected Time Complexity: O(V*E).
Expected Auxiliary Space: O(V).

 

Constraints:
1 ≤ V ≤ 500
1 ≤ E ≤ V*(V-1)
-1000 ≤ adj[i][j] ≤ 1000
0 ≤ S < V



*/

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<int> distance(100000, INT_MAX);
        
        queue<pair<int, int>>q;
        q.push({0, start});
        distance[start]=0;
        
        while(!q.empty())
        {
            int mulTimes= q.front().first;
            int product= q.front().second;
            q.pop();
            
            if(product== end){
                return mulTimes;
            } 
            for(auto it: arr)
            {
                int newProduct= (product * it) %100000;
                if(distance[newProduct]> mulTimes+1)
                {
                    distance[newProduct]= mulTimes+1;
                    q.push({mulTimes+1, newProduct});
                }
            }
            
        }
        return -1;
    }
};



/*
N-1 iterations needed because all nodes apart from 0 will be updated in N-1 iterations one by one
!Important testcase to show why dist[u]!=1e8 is needed, for self
shoutout to chatGPT
Example Test Case:
Vertices (V): 5
Edges (E): 4
Edge List: [0, 1, 2], [0, 2, 7], [1, 2, 4], [3, 4, -7]
Source (S): 0
Initial Setup:
dist array: [0, 1e8, 1e8, 1e8, 1e8] (initially set to infinity except the source which is 0)
Relaxation Steps:
1st Iteration:
Edge [0, 1, 2]:
dist[1] updated to dist[0] + 2 → 0 + 2 = 2
dist array: [0, 2, 1e8, 1e8, 1e8]
Edge [0, 2, 7]:
dist[2] updated to dist[0] + 7 → 0 + 7 = 7
dist array: [0, 2, 7, 1e8, 1e8]
Edge [1, 2, 4]:
dist[2] updated to dist[1] + 4 → 2 + 4 = 6 (since 6 < 7)
dist array: [0, 2, 6, 1e8, 1e8]
Edge [3, 4, -7]:
dist[3] is 1e8, so dist[3] + (-7) should not update dist[4] since dist[3] is not reachable
dist array remains: [0, 2, 6, 1e8, 1e8]
2nd Iteration:
Edge [0, 1, 2]: No update (dist[1] already 2)
Edge [0, 2, 7]: No update (dist[2] already 6)
Edge [1, 2, 4]: No update (dist[2] already 6)
Edge [3, 4, -7]: No update (dist[4] remains 1e8)
3rd Iteration:
Edge [0, 1, 2]: No update (dist[1] already 2)
Edge [0, 2, 7]: No update (dist[2] already 6)
Edge [1, 2, 4]: No update (dist[2] already 6)
Edge [3, 4, -7]: No update (dist[4] remains 1e8)
4th Iteration:
Edge [0, 1, 2]: No update (dist[1] already 2)
Edge [0, 2, 7]: No update (dist[2] already 6)
Edge [1, 2, 4]: No update (dist[2] already 6)
Edge [3, 4, -7]: No update (dist[4] remains 1e8)
Final Negative Cycle Check:
Edge [0, 1, 2]: No update (dist[1] already 2)
Edge [0, 2, 7]: No update (dist[2] already 6)
Edge [1, 2, 4]: No update (dist[2] already 6)
Edge [3, 4, -7]: No update (dist[4] remains 1e8)
Explanation:
If we didn't include the condition dist[u] != 1e8:

In the first iteration for edge [3, 4, -7], dist[3] is 1e8 (not reachable), but we would incorrectly try to update dist[4] to 1e8 - 7 = 99999993.
This results in an invalid distance for vertex 4.
By including dist[u] != 1e8:

The edge [3, 4, -7] is skipped during all iterations because dist[3] remains 1e8 (indicating vertex 3 is not reachable from the source).

*/
