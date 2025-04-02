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

//  1] Using Recursion – O(n) Time and O(n) Space
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


//  2] Using Level Order Traversal – O(n) Time and O(n) Space
    void LevelRightView(TreeNode* root, vector<int>&ans){
            if(!root)
                return;
            queue<TreeNode*>q;
            q.push(root);
            while(!q.empty()){
                int n = q.size();
                TreeNode* f = q.front();
                q.pop();

                if(f->right)
                    q.push(f->right);
                if(f->left)
                    q.push(f->left);

                ans.push_back(f->val);

                for(int i=1; i<n; i++){

                    TreeNode* f = q.front();
                    q.pop();

                    if(f->right)
                        q.push(f->right);
                    if(f->left)
                        q.push(f->left);

                }

            }
    }




//  3] Using Morris Traversal – O(n) Time and O(1) Space
    void MorrisRightView(TreeNode* root, vector<int>&res){
       int lvl = 0;
       
        while(root){
            if(root->right){
                int bd = 1;
                TreeNode* pred = root->right;
                while(pred->left != NULL && pred->left != root){
                    pred = pred->left;
                    bd++;
                }

                if(pred->left == NULL){
                    pred->left = root;
                    if(lvl == res.size())
                        res.push_back(root->val);
                    lvl++;
                    root = root->right;
                }else{
                    pred->left = NULL;
                    lvl -= bd;
                    root = root->left;
                }

            }else{
                if(lvl == res.size())
                    res.push_back(root->val);
                lvl++;
                root = root->left;
            }
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        int maxLevel = -1;
        //RecursiveRightView(root, 0, maxLevel, ans);
        //LevelRightView(root, ans);
        MorrisRightView(root, ans);
        return ans;
    }
};