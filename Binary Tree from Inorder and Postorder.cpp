/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  
    Node* contructBT(int &postIndex, int l, int r, vector<int>&postorder, vector<int>& inorder, unordered_map<int,int>&InorderIndex ){
            if( postIndex < 0 || l > r )
                return NULL;

            Node* root = new Node(postorder[postIndex]);
            int index = InorderIndex[ root->data ];
            postIndex--;
            
            root->right = contructBT(postIndex, index+1, r,postorder, inorder,  InorderIndex);
            root->left = contructBT(postIndex, l, index-1,postorder, inorder,  InorderIndex);
           
            return root;
    }

    // Function to return a tree created from postorder and inoreder traversals.
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        unordered_map<int,int>InorderIndex;
        int n = inorder.size();
        for(int i=0; i<n; i++){
            InorderIndex[ inorder[i] ] = i;
        }
        
        int postIndex = n-1;

        return contructBT(postIndex, 0, n-1, postorder, inorder,  InorderIndex);
    }
};
