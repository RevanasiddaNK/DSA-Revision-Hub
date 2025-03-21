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
//[Approach 1] Using Recursion – O(n) Time and O(h) Space
    int solve1(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int l = solve1(root->left);
        int r = solve1(root->right);

        return max(l,r)+1;
    }

//[Approach 2] Level Order Traversal using Null Delimiter – O(n) Time and O(n) Space
    int solve2(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int h = 0;
        while(!q.empty()){
           TreeNode* curr = q.front();
           q.pop();

           if(curr == NULL){
                h++;
                if(!q.empty())
                    q.push(NULL);
           }else{
                if(curr->left)  q.push(curr->left);
                if(curr->right)  q.push(curr->right);

           }
           
        }
        return h;
    }

//[Approach 3] Level Order Traversal without using Null Delimiter – O(n) Time and O(n) Space
    int solve3(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int h = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left)  q.push(curr->left);
                if(curr->right)  q.push(curr->right);
            }
            h++;
        }
        return h;
    }

    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

        int ans = -1;
        //ans =  solve1(root);
        //ans = solve2(root); 
        ans = solve3(root); 

        return ans;
    }
};