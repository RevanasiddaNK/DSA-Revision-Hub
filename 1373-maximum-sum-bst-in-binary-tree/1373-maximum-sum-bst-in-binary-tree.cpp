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
            bool isBST;
            BSTInfo(bool isBST, int max, int min, int sum){
                this->max = max;
                this->min = min;
                this->sum = sum;
                this->isBST = isBST;
            }
    };

    int maxSum = 0;

    BSTInfo findmaxSumBST(TreeNode* root){

        if(!root){
            return BSTInfo(true, INT_MIN, INT_MAX, 0);
        }

        BSTInfo left = findmaxSumBST(root->left);
        BSTInfo right = findmaxSumBST(root->right);

        if( (left.isBST && right.isBST)   && (left.max < root->val && root->val < right.min)   ){
            int totalSum = left.sum + right.sum + root->val;
            maxSum = max(totalSum, maxSum);
            return BSTInfo( true, max(root->val, right.max), min(root->val,left.min),  totalSum );
        }

        return BSTInfo( false, INT_MAX, INT_MIN, 0);
    }


    int maxSumBST(TreeNode* root) {
        BSTInfo temp = findmaxSumBST(root);
        return  maxSum;
    }
};