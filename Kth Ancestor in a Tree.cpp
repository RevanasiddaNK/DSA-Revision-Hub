void inorderTraversal(Node *root,  unordered_map<int, int>&ancestor){
    if(!root)
        return;
    
    if(root->left){
        ancestor[root->left->data] = root->data;
        inorderTraversal(root->left,ancestor );
    }
    
    if(root->right){
        ancestor[root->right->data] = root->data;
        inorderTraversal(root->right,ancestor );
    }
}

int kthAncestor(Node *root, int k, int node)
{

        unordered_map<int, int> ancestor;
        ancestor[root->data] = -1;
        inorderTraversal(root,ancestor );
        int cnt = k;

        while(cnt > 0 && ancestor.find(node) != ancestor.end()){
            node = ancestor[node];
            cnt--;
        }
        return node;

}
