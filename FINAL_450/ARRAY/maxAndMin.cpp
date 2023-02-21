//c++ program to find the max and min element of the array

#include<iostream>
using namespace std;
int findMAX(int *arr, int size)
{
    int max= arr[0];
    for(int i=0 ; i<size; i++)
    {
        if(max<arr[i])
        {
            max= arr[i];
        }
    }
    return max;
}
int findMIN(int * arr, int size)
{
    int min= arr[0];
    for(int i=0 ; i<size; i++)
    {
        if(min>arr[i])
        {
            min= arr[i];
        }
    }
    return min;
}

int main(){
    int size;
    int * arr = (int *)malloc(sizeof(int));
    cout<<"Enter the size of the array :\t";
    cin>>size;

    cout<<"Enter the array elements :\t";
    for(int i=0 ; i<size; i++)
    {
        cin>>arr[i];
    }
    int max= findMAX(arr, size);
    int min= findMIN(arr, size);

    cout<<"MAX element : \t"<<max<<endl;
    cout<<"MIN element : \t"<<min<<endl;

return 0;
}
