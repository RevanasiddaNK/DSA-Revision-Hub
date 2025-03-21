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

    bool BFSSolution(TreeNode* p, TreeNode* q) {
        queue<TreeNode*>q1;
        queue<TreeNode*>q2;
        q1.push(p);
        q2.push(q);

        while(! (q1.empty() || q2.empty() ) ){
            TreeNode* c1 = q1.front();
            TreeNode* c2 = q2.front();
            if(c1->val != c2->val)
                return 0;
           
            q1.pop();
            q2.pop();

            if(c1->left && c2->left) {
                q1.push(c1->left);
                q2.push(c2->left);
            } 
            else if(c1->left || c2->left  ){
                return 0;
            }
            if(c1->right && c2->right){
                q1.push(c1->right);
                q2.push(c2->right);
            }else if(c1->right || c2->right){
                return 0;
            }  
        }
        return q1.size() == q2.size();
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p == NULL && q == NULL){
            return 1;
        }else if(p == NULL || q == NULL){
            return 0;
        }

        bool ans = false;
        //ans =  DFSSolution(p,q);
        //ans =  BFSSolution(p,q);


        return ans;
    }
};