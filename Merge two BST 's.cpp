class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    
    void inorderTraversal(Node* root, vector<int>& inorder) {
        if (!root)
            return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->data);
        inorderTraversal(root->right, inorder);
    }
    
    vector<int> merge2SortedArray(Node *root1, Node *root2) {
        vector<int>inorder;
        vector<int>inorder1;
        inorderTraversal(root1, inorder1);
        vector<int>inorder2;
        inorderTraversal(root2, inorder2);
        
        int n1=inorder1.size(), n2=inorder2.size();
        
        int i=0,j=0;
        while( i <n1 && j <n2){
            if(inorder1[i] < inorder2[j] ){
                inorder.push_back(inorder1[i++]);
            }else{
                inorder.push_back(inorder2[j++]);
            }
        }
        
        while(i < n1){
            inorder.push_back(inorder1[i++]);
        }
        
        while(j < n2){
            inorder.push_back(inorder2[j++]);
        }
        return inorder;
    }
  

    Node* flattenBT(Node* root) {
        Node dummy(0);
        Node* prev = &dummy;
        Node* curr = root;
    
        while (curr) {
            if (!curr->left) {
                // Visit curr
                prev->right = curr;
                prev = curr;
    
                // Move to next
                curr = curr->right;
            } else {
                // Find inorder predecessor
                Node* pred = curr->left;
                while (pred->right && pred->right != curr) {
                    pred = pred->right;
                }
    
                if (!pred->right) {
                    // Thread: link predecessor back to curr
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    // Undo thread, visit curr
                    pred->right = nullptr;
                    prev->right = curr;
                    prev = curr;
    
                    // Remove left link, move on
                    curr->left = nullptr;
                    curr = curr->right;
                }
            }
        }
    
        // Terminate the list
        prev->right = nullptr;
        return dummy.right;
    }


// Merge two sorted right-skewed lists into a sorted vector
vector<int> merge(Node* root1, Node* root2) {
    vector<int> result;

    Node* head1 = flattenBT(root1);
    Node* head2 = flattenBT(root2);

    // Standard merge of two sorted linked lists
    while (head1 && head2) {
        if (head1->data <= head2->data) {
            result.push_back(head1->data);
            head1 = head1->right;
        } else {
            result.push_back(head2->data);
            head2 = head2->right;
        }
    }
    while (head1) {
        result.push_back(head1->data);
        head1 = head1->right;
    }
    while (head2) {
        result.push_back(head2->data);
        head2 = head2->right;
    }

    return result;
}

};
