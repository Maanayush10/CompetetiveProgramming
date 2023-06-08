//Kadane's algorithm implementation
#include<bits/stdc++.h>
 long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long max_so_far= INT_MIN, max_till_here= 0;
        for(int i=0; i<n; i++)
        {
            max_till_here+=arr[i];
            if(max_so_far<max_till_here){
                max_so_far= max_till_here;
            }
            if(max_till_here<0)
            {
                max_till_here=0;
            }
        }
        return max_so_far;
    }

int main(){
  int size=5;
  int arr[size]= {1,2,3,4,5};
  int ans = maxSubarraySum(arr, size);
  cout<<ans<<endl;
}
