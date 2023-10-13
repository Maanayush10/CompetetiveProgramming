#include<bits/stdc++.h>
using namespace std;

 void sort012(int a[], int n)
    {
        // code here 
        //dutch national algorithm problem
        int low=0, mid=0, high= n-1;
        while(mid<=high)
        {
            if(a[mid]==0)
            {
                swap(a[mid], a[low]);
                low++;
                mid++;
            }
            else if(a[mid]==2)
            {
                swap(a[mid], a[high]);
                high--;
            }
            else
            {
                mid++;
            }
        }
    }

int main()
{
  return 0;
}
