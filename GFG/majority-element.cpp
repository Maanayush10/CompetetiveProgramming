#include<bits/stdc++.h>
using namespace std;


//using moore's voting algo
//o(N) time and o(1) space
int majorityElement(int a[], int size)
    {
        int ele;
        int count=0;
        // your code here
       for(int i=0; i<size; i++)
       {
          if(count ==0)
          {
              count++;
              ele= a[i];
          }
          else if(a[i]==ele)
          {
              count ++;
          }
          else
          {
              count--;
          }
       }
       
       int count1=0;
       for(int i=0; i<size; i++)
       {
           if(a[i]==ele){ count1++;}
       }
       if(count1 > size/2)
       {
           return ele;
       }
       return -1;
    }


int main(){
  int arr ={2,3,4,5,6};
  int ans = majorityElement(arr, 5);
  cout<<ans;
  return 0;
}
