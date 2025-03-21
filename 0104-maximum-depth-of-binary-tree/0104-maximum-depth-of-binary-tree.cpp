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

    int solve1(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int l = solve1(root->left);
        int r = solve1(root->right);

        return max(l,r)+1;
    }

    int maxDepth(TreeNode* root) {
        return solve1(root);
    }
};