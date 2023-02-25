//Largest Sum Contiguous Subarray (Kadane’s Algorithm)

#include<bits/stdc++.h>
using namespace std;

//O(N) implementation
int maxSubArray3(int * arr, int size)
{
    int maxSum=0;
    int sum=0;
    for (int i = 0; i < size; i++)
    {
        sum = sum+arr[i];
        maxSum= max(sum, maxSum);
        if(sum<0)
        {
            sum=0;
        }

    }
    return maxSum;
    
}

//O(N^2) implementation
int maxSubArray2(int *arr, int size)
{
    int maxSum=0;
    for(int i=0; i<size; i++)
    {
    int sum=0;
        for(int j=i; j<size; j++)
        {
            sum= sum+arr[j];
            if(maxSum<sum)
            {
                maxSum= sum;
            }
        }
    }
    return maxSum;
}

//O(N^3) implementation
int maxSubArray(int *arr, int size)
{
    int maxSum=0;
    for(int i=0; i<size; i++)
    {
        for(int j=i; j<size; j++)
        {
            int sum=0;
            for(int k=i; k<j; k++)
            {
                // cout<<" "<<arr[k];
                sum= sum+arr[k];
                if(maxSum<sum)
                {
                    maxSum= sum;
                }
            }
            // cout<<endl;
        }
    }
    return maxSum;
}

int main(){

    int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int n = sizeof(a) / sizeof(a[0]);

    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
  
    // Function Call
    int max_sum = maxSubArray(a, n);
    int max_sum2 = maxSubArray2(a, n);
    int max_sum3 = maxSubArray3(a, n);
    cout << "Maximum contiguous sum is : " << max_sum;
    cout<<endl;
    cout << "Maximum contiguous sum is : " << max_sum2;
    cout<<endl;
    cout << "Maximum contiguous sum is : " << max_sum3;
    cout<<endl;
    return 0;

return 0;
}
