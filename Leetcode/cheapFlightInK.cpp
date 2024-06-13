/*

787. Cheapest Flights Within K Stops

There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 

Example 1:


Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
Example 2:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
Example 3:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
 

Constraints:

1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst

*/


//Got TLE in this one
// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
//                           int k) {
//         int rows = flights.size();
//         vector<vector<pair<int, int>>> adj(n);
//         // x-> {y1, dist1},{y2, dist2};
//         for (int i = 0; i < flights.size(); i++) {
//             adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
//         }
//         priority_queue<pair<int, pair<int, int>>,
//                        vector<pair<int, pair<int, int>>>, greater<>>
//             q;
//         q.push({0, {src, k}});
//         while (!q.empty()) {
//             auto node = q.top().second;
//             int currNode = node.first;
//             int stops = node.second;
//             int currCost = q.top().first;
//             q.pop();
//             if (currNode == dst) {
//                 return currCost;
//             }
//             if (stops >= 0) {
//                 for (auto it : adj[currNode]) {
//                     int destNode = it.first;
//                     int cost = it.second;
//                     int newCost = currCost + cost;
//                     q.push({newCost, {destNode, stops - 1}});
//                 }
//             }
//         }
//         return -1;
//     }
// };

//introduced dp array
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Create adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        // Priority queue to store (cost, (current_node, stops_left))
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;
        q.push({0, {src, k + 1}});

        // Dynamic programming table to store minimum cost to reach each node with given stops
        vector<vector<int>> dp(n, vector<int>(k + 2, INT_MAX));
        dp[src][k + 1] = 0;

        while (!q.empty()) {
            auto node = q.top().second;
            int currNode = node.first;
            int stops = node.second;
            int currCost = q.top().first;
            q.pop();

            // If we reach the destination, return the cost
            if (currNode == dst) {
                return currCost;
            }

            // If we still have stops left, explore neighbors
            if (stops > 0) {
                for (auto it : adj[currNode]) {
                    int destNode = it.first;
                    int cost = it.second;
                    int newCost = currCost + cost;

                    // Only proceed if the new cost is cheaper
                    if (newCost < dp[destNode][stops - 1]) {
                        dp[destNode][stops - 1] = newCost;
                        q.push({newCost, {destNode, stops - 1}});
                    }
                }
            }
        }
        return -1; 
    }
};
