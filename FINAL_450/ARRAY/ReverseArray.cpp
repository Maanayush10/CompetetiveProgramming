#include<iostream>
using namespace std;

void reverseArray(int * arr, int start, int end)
{
    while(start<end)
    {
        int temp= arr[start];
        arr[start]= arr[end];
        arr[end]= temp;
        start++;
        end--;
    }
}

void printArray(int *arr, int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main(){
    int size;
    int * arr= (int *)malloc(sizeof(int));
    cout<<"Enter the value of size :\t";
    cin>>size;
    cout<<"Enter the array elements :\t";
    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }
    cout<<"Array before reversal :\t";
    printArray(arr, size);
    reverseArray(arr, 0, 4);
    cout<<endl;
    cout<<"Array after reversal :\t";
    printArray(arr, size);
    cout<<endl;
return 0;
}
