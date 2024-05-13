/*

230. Kth Smallest Element in a BST
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

Example 1:

Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
 

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?

*/

//brute force approach -> traverse the tree and keep each node's value in a vector, sort the vector, and return the Kth smallest element
class Solution {
public:
    void traverse(TreeNode* root, vector<int>& traverseARR)
    {
        if(root==NULL)
        {
            return;
        }
        traverse(root->left,traverseARR);
        traverse(root->right,traverseARR);
        traverseARR.push_back(root->val);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> myArr;
        traverse(root, myArr);
        sort(myArr.begin(), myArr.end());

        for(int k: myArr)
        {
            cout<<" "<<k;
        }
        cout<<endl;
        return myArr[k-1];
    }
};
