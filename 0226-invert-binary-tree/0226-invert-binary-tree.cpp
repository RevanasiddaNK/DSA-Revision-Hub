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

    void invert(TreeNode* root) {
        if(root == NULL)
            return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        temp=NULL;
        invert(root->left);
        invert(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        TreeNode* curr = root;
        invert(curr);
        return root;
    }
};