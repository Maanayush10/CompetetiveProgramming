#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /*approach taking to loops; my i index increments after every outer for loop, and the j index checks on ezg iteration if my jth elemnt sums to make a target or not.*/
    vector<int> twoSum(vector<int> &nums, int target, int *a, int *b)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    //0 based indexing followed;
                    // return {i, j};
                    *a=i;
                    *b=j;
                    // return {a,b};
                    break;
                }
            }
        }
        return {};
    }
};
int main()
{
    Solution sol;
    vector<int> nums;
    int a, b;

    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);

    sol.twoSum(nums, 5,&a,&b);
    cout<<"The indexes required are : \t";
    cout<<a<<","<<b<<endl;
    return 0;
}
