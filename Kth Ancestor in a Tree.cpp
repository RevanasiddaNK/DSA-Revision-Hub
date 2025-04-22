

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
int kthAncestorSolve(Node *root, int k, int node){

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


bool solveRec(Node *root, int &k, int node,int &ans){
    
    if(!root)
        return false;
        
    if(root->data == node){
        k--;
        return true;
    }    
    
    bool left = solveRec(root->left, k, node, ans);
    
    if(left){
        if(k == 0){
            ans = root->data;
            k--;
            return false;
        }else{
            k--;
            return true;
        }
    }
    
    bool right = solveRec(root->right, k, node, ans);
    
    if(right){
        if(k == 0){
            ans = root->data;
            k--;
            return false;
        }else{
            k--;
            return true;
        }
    }
     return false;   
}


// not working
int iterativeSol(Node* root, int node, int k) {
    stack<Node*> s;
    vector<int> ancestors;
    bool found = false;

    while (root != nullptr || !s.empty()) {
        if (root != nullptr) {
            s.push(root);
            root = root->left;
        } else {
            Node* temp = s.top(); 
            s.pop();
            if (temp->data == node) {
                found = true;
                break;
            }
            if (temp->right != nullptr) {
                root = temp->right;
            }
        }
    }

    if (!found) 
        return -1;

  
    while (!s.empty() && k > 0) {
        ancestors.push_back(s.top()->data);
        s.pop();
        k--;
    }

 
    if ( k < 0 ) 
        return -1;

    return ancestors.back();
}


int kthAncestor(Node *root, int k, int node){
        
        int ans = -1;
        
        ans =  kthAncestorSolve(root,k,node);
        //bool check = solveRec(root, k, node, ans);
        //ans = iterativeSol(root, k, node);
        
        
        return ans;
}
