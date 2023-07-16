//Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

/*
    [1,2,3,4,5]

    k=3
    kth small element = 3
    
    
*/


/*

Approach used by me : Sort the given array and find the kth element

*/
#include<bits/stdc++.h>
using namespace std;


int KSmall(int *arr, int l , int r,int k)
{
    return arr[k-1];

}

int main(){
    int K;
    int * arr;
    arr= (int *)malloc(sizeof(int));

    int size;
    cout<<"Enter the size of the array: \t";
    cin>>size;

    cout<<"Enter the array elements :\t";
    for(int i = 0; i<size; i++)
    {
        cin>>arr[i];
    }

    cout<<"Enter the value of K (smaller than size) :\t";
    cin>>K;

    sort(arr, arr+size);

    int ans= KSmall(arr,0, size, K);

    cout<<"The Kth small element of the array is :\t"<<ans<<endl;



return 0;
}
