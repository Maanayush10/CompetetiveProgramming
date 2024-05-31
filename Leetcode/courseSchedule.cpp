/*

207. Course Schedule
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.

*/

class Solution {
private:
    // the dfs checks for any cycle and returns true if cycle is found
    bool dfs(int node, vector<int> adj[], vector<int>& vis,
             vector<int>& dfsVis) {
        vis[node] = 1;
        dfsVis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, dfsVis)) {
                    return true;
                }
            } else if (dfsVis[it]) {
                return true;
            }
        }
        dfsVis[node] = 0;
        return false;
    }

public:
    // if the graph has cycles,
    // then it will be impossible for people to complete all courses
    // so checkinh for the cycles in the graph
    // 2 visited arrays
    // To detect cycles in a directed graph using DFS, you need to maintain two
    // states for each node: whether it has been visited (vis) and whether it is
    // currently in the recursion stack (dfsVis). A cycle is detected if a node
    // is encountered that is already in the recursion stack
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> vis(numCourses, 0);
        vector<int> dfsVis(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, dfsVis)) {
                    return false;
                }
            }
        }
        return true;
    }
};
