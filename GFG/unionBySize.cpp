/*Refer to striver Union by Size Video*/

/*

Approach:
Union (U, V)
1) Find ultimate parent of u & v (pu & pv).
2)Find size if pu and pv.
3)Connect smaller size to larger size, always.

*/
//data-structure for UnionBySize
class DisjointSet
{
  vector<int> size, parent;
  public:
  DisjointSet(int n)
  {
    size.resize(n+1, 1);
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

  void unionBySize(int u, int v)
  {
    int ulp_u= findPar(u);
    int ulp_v= findPar(v);

    if(ulp_u==ulp_v) return;  //they belong to the same component
    if(size[ulp_u]<size[ulp_v])
    {
      parent[ulp_u]= ulp_v;
      size[ulp_v]+=size[ulp_u];
    }
    else if(size[ulp_v]<size[ulp_u])
    {
        parent[ulp_v]= ulp_u;
        size[ulp_u]+=size[ulp_v];
    }
    else
    {
      parent[ulp_v]= ulp_u;
      size[ulp_u]+=size[ulp_v];
    }
  }
}
