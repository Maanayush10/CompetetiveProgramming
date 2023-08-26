#include<bits/stdc++.h>
using namespace std;

int isPalindrome(string S)
	{
	    // Your code goes here
	    int j= S.length()-1;
	    string sNew="";
	    while(j>=0)
	    {
	        sNew= sNew + S[j];
	        j--;
	    }
	    if(S==sNew)
	    {
	        return 1;
	    }
	    return 0;
	}

int main()
{
  //main logic here
  return 0;
}
