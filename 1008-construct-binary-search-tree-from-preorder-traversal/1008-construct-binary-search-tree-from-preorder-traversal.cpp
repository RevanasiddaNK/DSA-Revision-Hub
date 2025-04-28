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

    TreeNode* constructBST(vector<int>& preorder, int &i, int bound, int& n){

        if(i >=  preorder.size() ||  preorder[i] >  bound)
            return NULL; 

        TreeNode* root = new TreeNode( preorder[i++]);

        root->left = constructBST(preorder ,i , root->val , n);
        root->right = constructBST(preorder ,i , bound , n);
     
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0, maxi = INT_MAX, n=preorder.size();
        return constructBST(preorder,i, maxi, n);
    }
};