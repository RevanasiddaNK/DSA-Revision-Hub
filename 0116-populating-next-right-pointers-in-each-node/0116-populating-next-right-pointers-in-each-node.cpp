/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if(!root)
            return root;

        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* f = q.front();
            q.pop();
            if(f->left){
                f->left->next = f->right;
                q.push(f->left);
            }

            if(f->right){
                if(f->next)
                    f->right->next =f->next->left;
                q.push(f->right);
            }
        }
        return root;
    }
};