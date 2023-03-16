#include<bits/stdc++.h>
using namespace std;
void reverseArr(int * arr, int size)
{
    int i=0, j=size-1;
    while(i<=j)
    {
        swap(arr[i++], arr[j--]);
    }
}
int main()
{
    int *arr;
    arr=(int *)malloc(sizeof(int));
    int size;
    // int arr[]={1,2,3,4,5,6};
    printf("Enter the size of the array: \t");
    scanf("%d", &size);
    printf("Enter the elements: \t");
    for (int i = 0; i < size; i++)
    {
        /* code */
        scanf("%d",&arr[i]);
    }

    reverseArr(arr,size);
    for (int i = 0; i < size; i++)
    {
        /* code */
        printf("%d ",arr[i]);
    }
    

return 0;
}
