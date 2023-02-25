//c++ program to Cyclically rotate an array by one

#include<bits/stdc++.h>
using namespace std;

void rotateArr(int * arr, int size)
{
    int temp= arr[size-1];
    for(int i=size-1; i>0; i--)
    {
       arr[i]= arr[i-1];
    }
    arr[0]= temp;
}
void printArr(int * arr, int size)
{
   for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    } 
}
int main(){
    int * arr= (int *)malloc(sizeof(int));
    int size;

    cout<<"Enter the size:\t";
    cin>>size;

    cout<<"Enter the array elements : \t";
    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }
    //before rotating print the array
    printArr(arr, size);


    //rotating the array by one
    rotateArr(arr, size);

    cout<<"After rotating the array :"<<endl;
    //print after rotating by 1
    printArr(arr, size);
    cout<<endl;
return 0;
}
