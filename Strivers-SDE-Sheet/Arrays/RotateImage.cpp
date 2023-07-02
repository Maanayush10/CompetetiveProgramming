#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
        int n= matrix.size();
        for (int i = 0; i < n; i++)
        {
            for(int j=0; j<i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
    }
int main()
{
  vector<vector<int>> m={{1,2,3},{4,5,6},{7,8,9}};
    cout<<"Before rotate :"<<endl;
    for (int i = 0; i < m.size(); i++)
    {
        for(int j=0; j<m[0].size(); j++)
        {
            cout<<" "<<m[i][j];
        }
        cout<<endl;
    }
    cout<<endl;

    rotate(m);

    cout<<"After rotate :"<<endl;
    for (int i = 0; i < m.size(); i++)
    {
        for(int j=0; j<m[0].size(); j++)
        {
            cout<<" "<<m[i][j];
        }
        cout<<endl;
    }
  return 0;
}
