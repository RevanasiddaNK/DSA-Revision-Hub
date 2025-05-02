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

    void findbinaryTreePaths(TreeNode* root, vector<vector<int>>&ans, vector<int>&path){
        if(!root){
                return;
        }
        if( !(root->left || root->right )){
            path.push_back(root->val);
            ans.push_back(path);
            path.pop_back();
            return;
        }

        path.push_back(root->val);

        findbinaryTreePaths(root->left, ans, path);
        findbinaryTreePaths(root->right, ans, path);

        path.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>>ans;
        vector<int>path;

        findbinaryTreePaths(root, ans, path);

        vector<string>svect;
        for(int i=0; i<ans.size(); i++){
            string s = "";
            for(int j=0; j<ans[i].size(); j++){
                if(j != ans[i].size()-1)
                    s += ( to_string(ans[i][j]) + "->" );
                else
                    s += to_string(ans[i][j]);
            }
            svect.push_back(s);
        }
        return svect;
    }
};