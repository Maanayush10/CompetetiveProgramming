#include<bits/stdc++.h>
using namespace std;

 bool cmp(Job arr1, Job arr2)
    {
        if(arr1.profit> arr2.profit){return true;}
        else if( arr1.profit== arr2.profit){
            return arr1.id>arr2.id;
        }
        return false;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<int>ans(2,0);
        sort(arr, arr+n, cmp);
        int maximum=0;
        for(int i=0; i<n; i++)
        {
            if(arr[i].dead>maximum)
            {
                maximum= arr[i].dead;
            }
        }
        int helpArr[maximum+1];
        for(int i=1; i<=maximum; i++)
        {
            helpArr[i]=-1;
        }
        int countJobs=0, JobProfit=0;
        
        for(int i=0; i<n; i++)
        {
            for(int j= arr[i].dead; j>0; j--)
            {
                if(helpArr[j]==-1)
                {
                    helpArr[j]=arr[i].profit;
                    countJobs++;
                    JobProfit+=arr[i].profit;
                    break;
                }
            }
        }
        ans[0]=countJobs;
        ans[1]=JobProfit;
        return ans;
    

int main()
{
  //main logic here
  return 0;
}
