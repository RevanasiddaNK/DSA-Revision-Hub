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

    int solve(TreeNode* root, int& ans){
        if(!root)
            return 0;
        int left = solve(root->left, ans);
        int right = solve(root->right, ans);
        ans = std::max({ ans, root->val, root->val + left, root->val + right, left+ root->val+ right  });

        return   std::max({ root->val + right , root->val + left,0 });

    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int temp = solve(root, ans);
        return ans;
    }
};