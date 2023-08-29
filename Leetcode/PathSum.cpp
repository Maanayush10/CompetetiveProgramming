#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//recursive approach
bool findTheDesPath(TreeNode* root, int targetSum, int current_sum)
    {
        if(root==NULL)
        {
            return false;
        }
        current_sum += root->val;
        if(root->left==NULL && root->right==NULL)
        {
            if(current_sum==targetSum)
            {
                return true;
            }
        }
        return findTheDesPath(root->left, targetSum, current_sum) || findTheDesPath(root->right, targetSum, current_sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
        {
            return false;
        }
        int currSum=0;
        currSum+=root->val;
        if(root->left==NULL && root->right==NULL)
        {
            if(currSum==targetSum)
            {
                return true;
            }
        }
        return findTheDesPath(root->left, targetSum, currSum) || findTheDesPath(root->right, targetSum, currSum);
    }

int main()
{
  //main logic here
  return 0;
}
