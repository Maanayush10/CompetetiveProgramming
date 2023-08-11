#include<bits/stdc++.h>
using namespace std;

//o(nlog(n)) approach
int max(int num1, int num2)
    {
        return num1>num2 ? num1: num2;
    }
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int count= 0;
    	int ans=1;
    	
    	int i=0, j=0;
    	
    	while(i < n)
    	{
    	    if(arr[i]<=dep[j]) //someone is already at the platform
    	    {
    	        count++;
    	        ans= max(count, ans);
    	        i++;
    	    }
    	    else if(arr[i]>dep[j])//platform is empty
    	    {
    	        count--;
    	        j++;
    	    }
    	}
    	return ans;
    }


int main()
{
  //main logic here
  return 0;
}
