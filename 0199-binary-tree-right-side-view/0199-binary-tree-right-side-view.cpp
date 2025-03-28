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

    void solveDFS(TreeNode* root, int lvl, int hd, unordered_map<int, pair<int,int> >&mp){

        if(!root)
            return;

        if(mp.find(lvl) == mp.end() ){
            mp[lvl] = make_pair(root->val, hd);
        }

        solveDFS(root->right, lvl+1, hd+1, mp);
        solveDFS(root->left, lvl+1, hd-1, mp);
        

    }


    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        // level -> val,hd(hd is maximized)
        unordered_map<int, pair<int,int> >mp;

        solveDFS(root, 0, 0, mp);
        int lvl = 0;
        while(mp.find(lvl) != mp.end() ){
            ans.push_back( mp[lvl].first );
            lvl++;
        }
        return ans;
    }
};