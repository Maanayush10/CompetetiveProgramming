#include <bits/stdc++.h>
using namespace std;

//brute force approach
int singleNumber(vector<int> &nums)
{
    //also can do long long int arr[INT_MAX];
    int arr[200] = {0};
    for (int i = 0; i < nums.size(); i++)
    {
        arr[nums[i]]++;
    }
    //running it only till nums.size(), cuz there are only that many entries 
    for (int i = 0; i < nums.size(); i++)
    {
        if (arr[i] == 1)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    vector<int> arr= {2,2,3,2};
    int ans= singleNumber(arr);

    cout<<"The single number is :"<<ans<<endl;

    return 0;
}
