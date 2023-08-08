#include <bits/stdc++.h>
using namespace std;



//brute force o(N^2)
int small(int num1,  int num2)
    {
        return num1<num2 ? num1 : num2;
    }
    int maxArea(vector<int>& height) {
        vector<int> maxArr;

        for(int i=0; i<height.size(); i++)
        {
            int max=0;
            for(int j=i+1; j<height.size(); j++)
            {
                int smallNum= small(height[i], height[j]);
                int prod= smallNum *(j-i);
                if(max < prod)
                {
                    max= prod;
                }
            }
            maxArr.push_back(max);
        }
        int result=maxArr[0];
        for(int i=0; i<maxArr.size(); i++)
        {
            if(maxArr[i]> result)
            {
                result= maxArr[i];
            }
        }
        return result;
    }



//optimized O(N) approach
int maxArea2(vector<int>& height) {
        int maxArea=0;
        int left= 0;
        int right= height.size()-1;

        while(left < right)
        {
            int width= right -left;
            maxArea = max(maxArea, min(height[right], height[left])*width);
            if(height[left]<height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxArea;
    }

int main()
{
  //main logic here
  return 0;
}
