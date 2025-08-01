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

    void inorderTraversal(TreeNode* root, vector<int>& inorder) {
        if (!root)
            return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }


    bool findTargetVector(TreeNode* root, int k) {
        vector<int>inorder;
        inorderTraversal(root, inorder);
        int s=0,e=inorder.size()-1;
        while(s < e){
            int sum = inorder[s] + inorder[e];
            if( sum == k)
                return 1;
            else if(sum < k)
                s++;
            else
                e--;
        }
        return 0;
    }

    bool twoSumMap(TreeNode* root, int k, unordered_set<int>&st){
        if(!root)
            return 0;
        if(st.find(k-root->val) != st.end()){
            return 1;
        }
        st.insert(root->val);
        bool left = twoSumMap(root->left,  k, st);
        if(left)    return 1;
        bool right = twoSumMap(root->right,  k, st);
        return right;
    }

    bool findTarget(TreeNode* root, int k) {
        //return findTargetVector(root,k);
        unordered_set<int> st;
       // st.insert(0);
        return twoSumMap(root, k, st);
    }
};