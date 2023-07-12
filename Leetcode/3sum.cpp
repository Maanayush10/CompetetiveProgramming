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

//better approach
vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>st;
        for(int i=0; i<nums.size(); i++)
        {
            set<int> hashset;
            for(int j=i+1; j<nums.size(); j++)
            {
             int third = -(nums[i]+nums[j]);
                if(hashset.find(third)!= hashset.end())
                {
                    vector<int> temp={nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[j]);  
            }
        }
        vector<vector<int>> result(st.begin(), st.end());
        return result;
    }

//using 2 pointers
vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        for(int i=0; i<nums.size(); i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1, k=nums.size()-1;
            vector<int>temp;

            while(j<k)
            {
                if(nums[i]+ nums[j]+nums[k]<0)
                {
                    j++;
                }
            else if(nums[i]+ nums[j]+nums[k]>0)
                {
                    k--;
                }
            else
                {
                   vector<int>temp={nums[i], nums[j], nums[k]}; 
                   ans.push_back(temp);
                   j++;
                   k--;
                   while(j<k && nums[j]==nums[j-1])j++;
                   while(j<k && nums[k]==nums[k+1])k--;
                }
            }
        }
        return ans;
    }


int main()
{
  //main logic here
  return 0;
}
