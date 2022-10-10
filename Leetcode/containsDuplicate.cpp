/*Given an integer array sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. After removing the duplicates return the number of elements in the unique array.*/

#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int> &nums)
{
     if(nums.size()==0) return 0;
        int i=0;
        for(int j=1; j<nums.size();j++)
        {
            if(nums[i]!=nums[j])
            {
                nums[++i]=nums[j];
            }
        }
       return i+1; 
}
int main()
{
    vector<int> arr ={1,2,2,3,4};

    int numberOfDup= removeDuplicates(arr);
    cout<<"The number of elements in the new array : "<<numberOfDup<<endl;


    return 0;
}
