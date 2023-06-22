// Product of Array Except Self

/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
You must write an algorithm that runs in O(n) time and without using the division operation.

*/

#include <bits/stdc++.h>
vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> output(nums.size(), 1);
        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);

        //create a left prod array
        for(int i=1; i<nums.size(); i++)
        {
            left[i]= left[i-1]*nums[i-1];
        }

        for(int i=nums.size()-2; i>=0; i--)
        {
            right[i]= nums[i+1]*right[i+1];
        }


        for(int i=0; i<nums.size(); i++)
        {
            output[i]=left[i]*right[i];
        }
        return output;
    }



int main(){
//write main f(n) is here->
return 0;
