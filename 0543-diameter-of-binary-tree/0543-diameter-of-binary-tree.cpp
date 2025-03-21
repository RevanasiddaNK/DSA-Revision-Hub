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
    int findH(TreeNode* root, int& ref) {
        if(root == NULL){
            return 0;
        }
        int l = findH(root->left,ref);
        int r = findH(root->right,ref);
        ref = max(ref, l+r);
        return max(l,r)+1;
    }


    int diameterOfBinaryTree(TreeNode* root) {
        int ref=0;
        int h = findH(root,ref);
        return ref;
    }
};