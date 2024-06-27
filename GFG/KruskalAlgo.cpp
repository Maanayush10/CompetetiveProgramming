/*refer to striver's video*/

/*

approach:
1) make an edges  vector<pair<int, pair<int, int>>>edges datastructure. {weight, {from, to}}
2) sort all the entries according to weight.
3) Then one by one in each entry check the ultimate parent of from and to nodes and then check if they are different or not, if yes, add their weights
to the MST.
4) if they have the same parent they already belong to the MST.
5) return the mstWt.

*/


class DisjointSet
{
    vector<int> parent, rank;
    public:
    DisjointSet(int n)
    {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0; i<n; i++)
        {
            parent[i]=i;
        }
    }
    
    int findPar(int node)
    {
        if(node== parent[node])
        {
            return node;
        }
        return parent[node]= findPar(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u= findPar(u);
        int ulp_v= findPar(v);
        
        if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]= ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u])
        {
            parent[ulp_v]= ulp_u;
        }
        else
        {
            parent[ulp_u]= ulp_v;
            rank[ulp_v]++;
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int, pair<int, int>>>edges;
        for(int i=0; i<V; i++)
        {
            for(auto it: adj[i])
            {
            int from= i;
            int to= it[0];
            int wt= it[1];
            edges.push_back({wt, {from, to}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mstWt=0;
        
        for(auto it: edges)
        {
            int wt= it.first;
            int u= it.second.first;
            int v= it.second.second;
            
            if(ds.findPar(u)!= ds.findPar(v))
            {
                mstWt+=wt;
                ds.unionByRank(u, v);
            }
        }
        return mstWt;
    }
};
