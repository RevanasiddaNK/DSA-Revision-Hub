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

    void inorderTraversal(TreeNode* root, vector<int>& inorder) {
        if (!root)
            return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }

    int inorderTraversal(TreeNode* root, int &k) {
        if (!root)
            return -1;
       

        int l = inorderTraversal(root->left, k);
        k--;
        if( k == 0)
            return root->val;
        int r = inorderTraversal(root->right, k);
        if( l != -1)
            return l;
        if(r != -1)
            return r;
        return -1;
    }

    int kthSmallest(TreeNode* root, int k) {
        /*
        vector<int>inorder;
        inorderTraversal(root, inorder);
        return inorder[k-1];
        */
        return inorderTraversal(root,k);
    }
};