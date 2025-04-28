/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* solve(TreeNode* root, int p, int q){
        if(!root)
            return NULL;
        
        if( root->val < p){
            return solve(root->right,p,q);
        }else if( root->val > q){
            return solve(root->left,p,q);
        }

        if(root->val == p ||  root->val == q ){
            return root;
        }

        if( root->val > p && root->val < q  )
            return root;   
        return NULL; 
    }



    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            int s = min(p->val,q->val);
            int b= max(p->val,q->val);
            return solve(root,s,b);
    }
};