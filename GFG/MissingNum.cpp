#include <bits/stdc++.h>
//GFG Missing number in array


 int missingNumber(vector<int>& array, int n) {
        //your code here
        //using sum of numbers
        int sumArr=0;
        
        for(int i=0; i<array.size();i++)
        {
            sumArr+=array[i];
        }
        int sumOfN= (n*(n+1))/2;
        return sumOfN - sumArr;
    }


int main(){
  vector<int>arr={1,2,3,5};
  int n=5;
  int ans = missingNumber(arr, n);
  cout<<ans<<endl;
  return 0;
}
