/*

Validate Binary Search Tree
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left 
subtree
 of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

*/

//brute force solution:
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
  //using inorder traversal
    void traverse(TreeNode* root, vector<int>&arr)
    {
        if(root==NULL)
        {
            return;
        }
        traverse(root->left, arr);
        arr.push_back(root->val);
        traverse(root->right, arr);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> myArr, myArr2;
        traverse(root, myArr);

        if(root==NULL){return false;}
        for(int k: myArr)
        {
            myArr2.push_back(k);
        }
        if(myArr.size()==1){return true;}//if arr size is one
        sort(myArr2.begin(), myArr2.end());
        int i=0, j=i+1;
        while(j<myArr2.size())
        {
            if(myArr2[i]==myArr2[j]){return false;}
            i++;j++;
        }
        if(myArr2[0]==myArr[myArr.size()-1]){return false;}
        return myArr==myArr2;
    }
};
