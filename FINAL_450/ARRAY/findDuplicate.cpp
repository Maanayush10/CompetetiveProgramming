#include <bits/stdc++.h>
using namespace std;

// O(N^2) implemenation
int findDuplicate(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                return arr[j];
            }
        }
    }
    return -1;
}

// O(N) implementation
int findDuplicate2(vector<int> nums)
{
    unordered_set<int> u;

    for (int i = 0; i < nums.size(); i++)
    {
        /* code */
        if (u.count(nums[i]))//-->checking if the number is a present in the unordered set or not
        {
            return nums[i];
        }
        u.insert(nums[i]);
    }
    return -1;
}
int main()
{
    // int size;
    // int *arr;
    // arr = (int *)malloc(sizeof(int));

    // cout << "Enter the size of the array:\t";
    // cin >> size;
    // cout << "Enter the array elements:\t";

    // for (int i = 0; i < size; i++)
    // {
    //     /* code */
    //     cin >> arr[i];
    // }
    vector<int> arr ={1,3,4,2,2,5};
    int num = findDuplicate2(arr);
    if (num == -1)
    {
        cout << "No number is repeated" << endl;
    }
    else
    {
        cout << "The number repeated is :" << num << endl;
    }

    return 0;
}
