/*

653. Two Sum IV - Input is a BST

Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

 

Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:


Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105

*/

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
class Solution {
public:
    void traverse(TreeNode * root, vector<int> &arr)
    {
        if(root==nullptr)
        {
            return;
        }
        traverse(root->left, arr);
        arr.push_back(root->val);
        traverse(root->right, arr);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        traverse(root, inorder);
        for(int i=0;i<inorder.size(); i++)
        {
            for(int j=i+1; j<inorder.size();j++)
            {
                if(inorder[i]+inorder[j]==k)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
