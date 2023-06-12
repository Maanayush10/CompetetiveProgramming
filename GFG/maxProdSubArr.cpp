long long maxProduct(vector<int> arr, int n) {
	    // code here
	   long prefix=1, suffix=1, ans= INT_MIN;
	   for(int i=0; i<arr.size(); i++)
	   {
	       if(prefix ==0){prefix =1;}
	       if(suffix==0){suffix=1;}
	       
	       prefix= arr[i]*prefix;
	       suffix= arr[n-i-1]*suffix;
	       
	       ans= max(ans,max(prefix, suffix));
	   }
	   return ans;
	}

int main()
{
  vector<int> arr={1,2,3,-4,5};
  int ans=maxProduct(arr, arr.size());
  cout<<ans<<endl;
  return 0;
}
