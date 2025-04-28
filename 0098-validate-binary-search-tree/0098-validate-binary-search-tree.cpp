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

    void inorderTraversal(TreeNode* root, vector<int>&inorder){
        if(!root)
            return;
        inorderTraversal(root->left,inorder );
        inorder.push_back(root->val);
        inorderTraversal(root->right,inorder );
    }

    bool isValidBSTinorderTraversal(TreeNode* root) {
        vector<int>inorder;
        inorderTraversal(root,inorder );
        int n = inorder.size();
        for(int i=1; i<n; i++){
            if(inorder[i-1] >= inorder[i]){
                return 0;
            }
        }
        return 1;
    }

    bool solveMinMax( TreeNode* root,  long long min , long long max ){
        if(!root)
            return 1;
       
        if(min >= root->val || max <= root->val ){
            return 0;
        }

        bool left = solveMinMax(root->left, min, root->val);
        bool right = solveMinMax(root->right, root->val, max);
        return right && left;
    }

    bool isValidBST(TreeNode* root) {
        bool ans = false;
        //ans = isValidBSTinorderTraversal(root);
        ans = solveMinMax(root, LLONG_MIN, LLONG_MAX);

        return ans;
    }
};