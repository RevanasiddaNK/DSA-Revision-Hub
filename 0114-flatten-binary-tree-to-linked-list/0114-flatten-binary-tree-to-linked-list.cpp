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

    void inOrder(TreeNode* root,  queue<TreeNode*>&q){
        if(!root)
            return;
        
        q.push(root);
        inOrder(root->left, q);
        inOrder(root->right, q);
    }
    
    void flattenQueue(TreeNode* root) {
        if(!root)
            return;
        queue<TreeNode*>q;
        inOrder(root, q);
        queue<TreeNode*>q1;
        root = q.front();
        root->left = NULL;
        q.pop();
        while(!q.empty()){
            TreeNode* f = q.front();
            q.pop();
            root->right = f;
            f->left = NULL;
            root = root->right;
        }
    }

    void flatten(TreeNode* root) {
        //flattenQueue(root);

        if( !root || ( root->left == NULL && root->right == NULL) )
            return;
        
        if(root->left){

            TreeNode* tempRight = root->right;
            flatten(root->left);
            root->right = root->left;
            root->left = NULL;
            
            TreeNode* temp = root;
            while(temp->right)
                temp = temp->right;
            
            temp->right = tempRight;
            flatten(tempRight);
        }else{
            flatten(root->right);
        }

    }
};