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

    TreeNode* constructBST(vector<int>&inorder, int s, int e){
        if(s > e){
            return NULL;
        }

        int m = s+(e-s)/2 ;
        TreeNode* root = new TreeNode( inorder[ m ] );
        root->left = constructBST(inorder, s, m-1 );
        root->right = constructBST(inorder, m+1, e );
        return root;
    }


    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        inorderTraversal(root, inorder);
        return constructBST(inorder, 0, inorder.size()-1 );
    }
};