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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>>ans;
            if(root == NULL)
                return ans;

            int r =0;
            queue<TreeNode*>q;
            q.push(root);
            while(!q.empty()){
                vector<int>temp;
                int n = q.size();
                for(int i=0; i<n; i++){

                    temp.push_back( q.front()->val );
                    
                    if(q.front()->left)  q.push(q.front()->left);
                    if(q.front()->right)  q.push(q.front()->right);
                    q.pop();
                }
                if(r%2){
                    reverse(temp.begin(), temp.end());
                }
                ans.push_back(temp);
                r++;

            }


            return ans;
    }
};