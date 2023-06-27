#include<bits/stdc++.h>
using namespace std;

int main(){
    int count= 5;
    int countT=0;
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
    // cout<<"**********************___________________";
    for (int i = 5; i >0; i--)
    {
        /* code */
        for (int j = i; j > 0; j--)
        {
            /* code */
            cout<<"*";
        }
        for(int k =0; k<(2*countT); k++)
        {
            cout<<" ";
        }

        for (int j = i; j > 0; j--)
        {
            /* code */
            cout<<"*";
        }
        countT++;
        cout<<endl;
        
    }
    
return 0;
}
