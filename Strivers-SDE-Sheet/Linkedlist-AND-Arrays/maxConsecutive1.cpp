#include <bits/stdc++.h>
using namespace std;

 int findMaxConsecutiveOnes(vector<int>& nums) {
        int max=0;
        int count=0;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==0)
            {
                count=0;
            }
            else
            {
                count++;
                if(max<count)
                {
                    max=count;
                }
            }
        }
        return max;
    }
int main() 
{
  //main logic here
  return 0;
}
