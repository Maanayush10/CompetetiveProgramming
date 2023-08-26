#include<bits/stdc++.h>
using namespace std;

//optimised approach no extra space (in place)
int isPalindrome2(string S)
	{
	    // Your code goes here
	    int i=0;
	    int j= S.length()-1;
	    while(i<j)
	    {
	        if(S[i]!=S[j])
	        {
	            return 0;//  it is not a pallindrome
	        }
	       i++;
	       j--;
	    }
	    return 1; //it is a pallindrome
	}


// below got TLE
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
