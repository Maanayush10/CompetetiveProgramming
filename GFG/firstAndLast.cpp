//First and last occurrences of x
#include<stdio.h>
using namespace std;

//O(N) Approach
vector<int> find(int arr[], int n , int x )
    {
        // code here
        int i=0, j=n-1;
        vector<int> res(2,-1);
        while(i<n)
        {
            if(arr[i]==x)
            {
                res[0]=i;
                break;
            }
            i++;
        }
        while(j>=0)
        {
            if(arr[j]==x)
            {
                res[1]=j;
                break;
            }
            j--;
        }
        return res;
    }

int main()
{
//main logic here
return 0;
}
