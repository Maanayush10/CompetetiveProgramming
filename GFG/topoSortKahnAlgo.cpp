/*

Topological sort
Given an adjacency list for a Directed Acyclic Graph (DAG) where adj_list[i] contains a list of all vertices j such that there is a directed edge from vertex i to vertex j, with  V  vertices and E  edges, your task is to find any valid topological sorting of the graph.

 

In a topological sort, for every directed edge u -> v,  u must come before v in the ordering.

 

Example 1:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 3, 2, 1, 0.
Example 2:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 5, 4, 2, 1, 3, 0.
Your Task:
You don't need to read input or print anything. Your task is to complete the function topoSort()  which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns an array consisting of the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them. If your returned topo sort is correct then the console output will be 1 else 0.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).

Constraints:
2 ≤ V ≤ 104
1 ≤ E ≤ (N*(N-1))/2



*/

/*

Kahn's Algorithm:
The algorithm works by repeatedly finding vertices with no incoming edges, 
removing them from the graph, and updating the incoming edges of the remaining vertices. 
This process continues until all vertices have been ordered.


Algorithm:
  Add all nodes with in-degree 0 to a queue.
  While the queue is not empty:
    Remove a node from the queue.
    For each outgoing edge from the removed node, decrement the in-degree of the destination node by 1.
    If the in-degree of a destination node becomes 0, add it to the queue.
  If the queue is empty and there are still nodes in the graph, the graph contains a cycle and cannot be topologically sorted.
  The nodes in the queue represent the topological ordering of the graph.

*/

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>indegree(V, 0);
	    vector<int>result;
	    queue<int>q;
	    //calculate all the indegrees
	    for(int i=0; i<V; i++)
	    {
	        for(auto it: adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    for(int i=0; i<indegree.size(); i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    while(!q.empty())
	    {
	        int node= q.front();
	        q.pop();
	        result.push_back(node);
	        for(auto it: adj[node])
	        {
	            indegree[it]--; //u cannot add it to an else statement as 
	                            //in the last iteration when it has to add the element
	                            // to the q, it will come out of the while loop, 
	                            //as the q becomes empty.
	            if(indegree[it]==0)
	            {
	                q.push(it);
	            }
	        }
	    }
	   // for(auto it: result)
	   // {
	   //     cout<<" "<<it<<" ";
	   // }
	    return result;
	}
};
