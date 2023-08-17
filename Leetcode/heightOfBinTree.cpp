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

#include <bits.std/c++.h>
using namespace std;

//O(N) space and time complexity
int maxDepth(TreeNode* root) {
        if (root== NULL)
        {
            return 0;
        }
        else
        {
            int ldepth= maxDepth(root->left);
            int rdepth = maxDepth(root->right);

            if(ldepth > rdepth)
            {
                return ldepth+1;
            }
            else
            {
                return rdepth+1;
            }
        }

int main()
{
  //main logic here
  return 0;
}
