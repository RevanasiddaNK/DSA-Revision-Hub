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

    TreeNode* contructBT(int &preIndex, int n, int l, int r, vector<int>& preorder, vector<int>& inorder, unordered_map<int,int>&InorderIndex ){
            if( preIndex >= n || l > r )
                return NULL;

            TreeNode* root = new TreeNode(preorder[preIndex]);
            int index = InorderIndex[ root->val ];
            preIndex++;
            root->left = contructBT(preIndex, n, l, index-1, preorder, inorder,  InorderIndex);
            root->right = contructBT(preIndex, n, index+1, r, preorder, inorder,  InorderIndex);
            return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int,int>InorderIndex;
        int n = inorder.size();
        for(int i=0; i<n; i++){
            InorderIndex[ inorder[i] ] = i;
        }
        int preIndex = 0;

        return contructBT(preIndex, n, 0, n-1, preorder, inorder,  InorderIndex);;

    }
};