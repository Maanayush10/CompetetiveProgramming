#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)
        {
            return false;
        }
        
        if(n==1)
        {
            return true;
        }
        if(n%2!=0)
        {
            return false;
        }
        return isPowerOfTwo(n/2);
    }
};

int main()
{
    int num;
    cout<<"Enter a number: "<<endl;
    cin>>num;

    Solution sol;
    bool check=sol.isPowerOfTwo(num);

    cout<<endl;
    cout<<check<<endl;
    return 0;
}