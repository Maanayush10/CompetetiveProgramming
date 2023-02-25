// Minimize the Heights II
//O(N) Implementation


#include <bits/stdc++.h>
using namespace std;
int max(int * arr, int size)
{
    int max=0;
    for(int i=0 ; i<size; i++)
    {
       if(max<arr[i])
       {
        max= arr[i];
       }
    }
    return max;
    
}

int min(int * arr, int size)
{
    int min=arr[0]; //min != 0 as all the elements of of the arr are positive and 0 will stay as minimum showing wrong minimum
    for(int i=0 ; i<size; i++)
    {
       if(min>arr[i])
       {
        min= arr[i];
       }
    }
    return min;
    
}
int minHeight(int *arr, int k, int size)
{
    //calculate average height of the array
    int sum=0;
    for(int i=0 ; i<size; i++)
    {
        sum = sum+arr[i];
    }
    int avg = sum/size;

    for(int i=0; i<size; i++)
    {
        if(arr[i]>avg)
        {
           arr[i]= max(0,arr[i]-k);
        }
        else
        {
            arr[i]= arr[i]+k;
        }
    }
    int tallest = max(arr, size);
    int smallest = min(arr, size);

    return tallest- smallest;
}
int main()
{
    int arr[] ={1, 5, 8, 10};
    int K = 2;

    int size = sizeof(arr)/sizeof(arr[0]);

    int ans = minHeight(arr, K, size);

    cout<<"Required answer : "<<ans<<endl;

    return 0;
}
