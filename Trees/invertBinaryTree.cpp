/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <algorithm>
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
        else if(root->left==NULL && root->right==NULL )
            return root;
        else
        {
            swap(root->left, root->right);
            root->left=invertTree(root->left);
            root->right=invertTree(root->right);
            return root;
        }
        
    }
};