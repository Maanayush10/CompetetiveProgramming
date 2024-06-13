/*

743. Network Delay Time
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
 

Constraints:

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

*/

/*

DON'T CONFUSE:
in the first second it will signal all nodes connected to the source at once, and so on.
Thus taking the first example, in 1st second, it will reach node 1 and node 3 in 1st second then in 2nd
second it will go from node 3 to node 4. the max to reach any node in the array is the max time it will take to reach all nodes.
*/


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> visited(n + 1, INT_MAX);
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        // priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int,
        // int>>>, greater<>>q;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.push({0, k});
        int time = INT_MAX;
        visited[k] = 0;
        while (!q.empty()) {
            int node = q.top().second;
            int timeTaken = q.top().first;
            q.pop();
            for (auto it : adj[node]) {
                int newTimeTaken = it.second + timeTaken;
                if (visited[it.first] > newTimeTaken) {
                    visited[it.first] = newTimeTaken;
                    q.push({newTimeTaken, it.first});
                }
            }
        }
         // Find the maximum time taken to reach any node
        int maxTime = *max_element(visited.begin() + 1, visited.end());
        return maxTime == INT_MAX ? -1 : maxTime;
    }
};
