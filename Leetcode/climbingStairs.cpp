#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int climbingStairs(int n)
    {
        vector<int> arr;
        arr.resize(n + 1);
        arr[0] = 1;
        arr[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        return arr[n];
    }
};
int main()
{

    int n;
    cout << "Enter the value of N : " << endl;
    cin >> n;

    Solution sol;
    int ans=sol.climbingStairs(n);
    cout<<"Number of attempts required: "<<n<<endl;
    return 0;
}
