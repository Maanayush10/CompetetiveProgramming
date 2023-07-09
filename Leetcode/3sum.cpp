#include<bits/stdc++.h>
using namespace std;
//brute force method
vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>st;
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                for(int k=j+1; k<nums.size(); k++)
                {
                    vector<int> temp;
                    if(nums[i]+nums[j]+nums[k]==0)
                    {
                       temp= {nums[i], nums[j], nums[k]};
                       sort(temp.begin(), temp.end());
                       st.insert(temp);
                    }
                    
                }
            }
        }
        vector<vector<int>> result(st.begin(), st.end());
        return result;
    }


int main()
{
  //main logic here
  return 0;
}
