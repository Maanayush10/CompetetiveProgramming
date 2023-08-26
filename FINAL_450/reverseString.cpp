#include<bits/stdc++.h>
using namespace std;
// o(1) space
void swap(char &x, char &y)
    {
        char c= x;
        x=y;
        y=c;
    } 
    void reverseString(vector<char>& s) {
        int i=0, j=s.size()-1;
        while(i<j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

int main()
{
  //main logic here
  return 0;
}
