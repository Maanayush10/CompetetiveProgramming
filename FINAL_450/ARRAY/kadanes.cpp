#include<bits/stdc++.h>
using namespace std;

//using GFG algo 
int maxSubArr(int * arr, int n)
{
    int maxSum=INT_MIN,sum=0;

    for(int i=0; i<n; i++)
    {
        sum= sum+arr[i];
        if(maxSum<sum)
        {
            maxSum= sum;
        }
        if(sum<0)
        {
            sum=0;
        }
    }
    return maxSum;
}

int main(){
    // int N;
    // printf("Enter the value of N:\t");
    // scanf("%d", &N);

    int arr[]={1,2,3, -2};
    for(int i=0; i<5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("Max sum of contiguos subArr: %d\n", maxSubArr(arr, 4));
return 0;
}