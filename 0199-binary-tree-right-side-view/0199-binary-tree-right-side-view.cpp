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

    void RecursiveRightView(TreeNode* root, int lvl, int &maxLevel, vector<int>&ans){

        if(!root)
            return;

        if(lvl > maxLevel ){
           ans.push_back(root->val);
           maxLevel = lvl;
        }

        RecursiveRightView(root->right, lvl+1, maxLevel, ans);
        RecursiveRightView(root->left, lvl+1, maxLevel, ans);
        

    }


    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        int maxLevel = -1;
        RecursiveRightView(root, 0, maxLevel, ans);

        return ans;
    }
};