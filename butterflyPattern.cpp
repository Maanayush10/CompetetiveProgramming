#include<bits/stdc++.h>
using namespace std;

int main(){
    int count= 5;
    for (int i = 0; i < 5; i++)
    {
        /* code */
        for (int j = 0; j <= i; j++)
        {
            /* code */
            cout<<"*";
        }
        for(int k =2*(count-1); k>0; k--)
        {
            cout<<" ";
        }
        for (int j = 0; j <= i; j++)
        {
            /* code */
            cout<<"*";
        }
        count--;
        cout<<endl;
        
    }
    
return 0;
}
