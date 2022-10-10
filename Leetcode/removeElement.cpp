/*Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. */

#include<bits/stdc++.h>
using namespace std;
int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0) return 0;
        int i=0;
        for(int j=0; j<nums.size(); j++)
        {
            if(nums[j]!=val)
            {
                nums[i]=nums[j];
                i++;
            }
        }
        return i;
        
    }

int main()
{
    vector<int> arr={1, 2,3,3,5};

    int tellNum= removeElement(arr, 3);

    cout<<"The number of elements after removing the required number is:"<<tellNum<<endl;
}