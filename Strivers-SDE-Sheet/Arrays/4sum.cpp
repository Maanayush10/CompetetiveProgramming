#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size= nums.size();
        set<vector<int>> st;
        for(int i=0; i<size; i++)
        {
            for(int j=i+1; j<size; j++)
            {
                set<long long> hashset;
                for(int k=j+1; k<size; k++)
                {
                    long long sum= nums[i]+nums[j];
                    sum+= nums[k];
                    long long fourth = target - sum;
                    if(hashset.find(fourth) != hashset.end())
                    {
                        vector<int> temp= {nums[i], nums[j], nums[k], int(fourth)};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
                
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
int main()
{
  //main logic here
  return 0;
}
