#include<bits/stdc++.h>
using namespace std;
//t.c. - (O(Nlog(N)+ O(N)
//s.c. - (O(1))

    static bool cmp(Item i1, Item i2)
    {
        double vp1= (double)i1.value/(double)i1.weight;
        double vp2= (double)i2.value/(double)i2.weight;
        
        if(vp1>vp2){return true;}
        else if(vp1<vp2){return false;}
        else{ return false;}
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr+n, cmp);
        
        int currWeight=0;
        double finalVal=0.0;
        double valuePerWei=0;
        //just to check if the sorting is done properly or not
        // for(int i=0; i<n; i++)
        // {
        //     cout<<" "<<arr[i].value;
        // }
        // cout<<endl;
        // for(int i=0; i<n; i++)
        // {
        //     cout<<" "<<arr[i].weight;
        // }
        // cout<<endl;
        
        for(int i=0; i<n; i++)
        {
            if(currWeight + arr[i].weight <=W)
            {
               currWeight+=arr[i].weight;
               finalVal+=arr[i].value;
            }
            else
            {
                int remain = W - currWeight;
                valuePerWei= (double)arr[i].value / (double)arr[i].weight;
                finalVal+= remain * valuePerWei;
                break;
            }
        }
        return finalVal;
    }


int main()
{
  //main logic here
  return 0;
}
