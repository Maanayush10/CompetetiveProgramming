/*Refer to striver Union by Rank Video*/

/*

Approach:
Union (U, V)
1) Find ultimate parent of u & v (pu & pv).
2)Find rank if pu and pv.
3)Connect smaller rank to larger rank, always.

*/
//data-structure for UnionByRank
class DisjointSet
{
  vector<int> rank, parent;
  public:
  DisjointSet(int n)
  {
    rank.resize(n+1, 0);
    parent.resize(n+1);
    for(int i=0; i<=n; i++)
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

    if(ulp_u==ulp_v) return;  //they belong to the same component
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
      parent[ulp_v]= ulp_u;
      rank[ulp_u]++;
    }
  }
}
