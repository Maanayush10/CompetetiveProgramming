//Move all negative numbers to beginning and positive to end with constant extra space
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int arr[] ={1 ,2 , 3, 4 , -1 , -3, 0, 5, -6};
    int size= sizeof(arr)/sizeof(arr[0]);
    // sort(arr, arr+size);    //sorting in ascending order
    sort(arr, arr+size, greater<int>()); //sortinf in descending order

    for(int i=0 ; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }

return 0;
}
