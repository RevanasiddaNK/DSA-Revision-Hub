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

    class BSTInfo{
        public:
            int max;
            int min;
            int sum;
            BSTInfo(int max, int min, int sum ){
                this->max = max;
                this->min = min;
                this->sum = sum;
            }
    };

    BSTInfo findmaxSumBST(TreeNode* root){

        if(!root){
            return BSTInfo(INT_MIN, INT_MAX, 0);
        }

        BSTInfo left = findmaxSumBST(root->left);
        BSTInfo right = findmaxSumBST(root->right);

        if( left.max < root->val && root->val < right.min   ){
return BSTInfo( max(root->val, right.max)  ,min(root->val,left.min) , (left.sum + right.sum + root->val)  );
        }

        return BSTInfo( INT_MAX, INT_MIN, max(left.sum, right.sum ));
    }


    int maxSumBST(TreeNode* root) {
        int ans = findmaxSumBST(root).sum;
        return ans < 0 ? 0 : ans;
    }
};