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

    bool DFSSolution(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return 1;
        }else if(p == NULL || q == NULL){
            return 0;
        }
        if(p->val != q->val)
            return 0;
        bool l = DFSSolution(p->left, q->left);
        bool r = DFSSolution(p->right, q->right);

        return l&&r;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = false;
        ans =  DFSSolution(p,q);

        return ans;
    }
};