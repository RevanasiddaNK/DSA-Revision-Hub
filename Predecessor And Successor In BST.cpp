/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

void inorderTraversal(TreeNode* root, vector<int>& inorder) {
    if (!root)
        return;
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

    void inorderIterativeStack(TreeNode* root, vector<int>& inorder) {
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (!st.empty() || curr) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();
            inorder.push_back(curr->data);
            curr = curr->right;
        }
    }

    void inorderIterativeMorris(TreeNode* root, vector<int>& inorder){
        TreeNode* curr = root;
        while(curr){
            if( !(curr->left)){
                inorder.push_back(curr->data);
                curr = curr->right;
            }else{
                TreeNode* pred = curr->left;
                while(pred->right && pred->right != curr )
                    pred = pred->right;
                if(pred->right == NULL){
                    pred->right = curr;
                    curr = curr->left;
                }
                else{
                    pred->right = NULL;
                    inorder.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
    }


pair<int, int> predecessorSuccessor(TreeNode *root, int key) {
    vector<int> inorder;
    //inorderTraversal(root, inorder);
    //inorderIterativeStack(root, inorder);
    inorderIterativeMorris(root, inorder);
    int i = 0, n = inorder.size();
    int pred = -1, succ = -1;
    for (i = 0; i < n; i++) {
        if (inorder[i] < key) {
            pred = inorder[i];
        }
        else if (inorder[i] > key) {
            succ = inorder[i];
            break;
        }
    }

    return {pred,succ};
}

