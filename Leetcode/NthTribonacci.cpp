#include<iostream>
using namespace std;

class Solution
{
    public:
        int getTrib(int n)
        {
            if(n==0)
            {
                return 0;
            }
            if(n<3)
            {
                return 1;
            }
            int x=0, y=1, z=1, ans;

            for (int i = 3; i <=n; i++)
            {
                /* code */
                ans=x+y+z;
                x=y;
                y=z;
                z=ans;
            }
            return ans;
        }
};

int main(){
    int n;
    cout<<"Enter the value of N:"<<endl;
    cin>>n;

    Solution sol;
    int ans= sol.getTrib(n);

    cout<<"The Nth tribonacci number is  :"<<ans<<endl;
return 0;
}
