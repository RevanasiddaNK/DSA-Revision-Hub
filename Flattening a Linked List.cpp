/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
  

    
    Node* findMiddleNode(Node* head){
        Node* s=head;
        Node* f=head;
        Node* prev = nullptr;
        while(f != NULL){
            prev = s;
            s = s->bottom ;
            f = f->bottom ;
            if(f)
                f = f->bottom;
        }
        Node* midNode = prev ->bottom;
        prev->bottom  = NULL;
        return  midNode;
    }

    Node* merge(Node* left, Node* mid){
        Node* nh = new Node(-1);
        Node* nt = nh;

        while(left && mid ){
            if(left->data <= mid->data){
                nt->bottom  = new Node(left->data);
                left = left->bottom ;
            }else{
                nt->bottom  = new Node(mid->data);
                mid = mid->bottom ;
            }
            nt = nt->bottom;
        }

        while(left){
            nt->bottom  = new Node(left->data);
            left = left->bottom ;
            nt = nt->bottom;
        }

         while(mid){
            nt->bottom  = new Node(mid->data);
            mid = mid->bottom;
            nt = nt->bottom;
        }

        return nh->bottom ;
    }

    Node* sortList(Node* head) {
        if(!head || !head->bottom )
            return head;

    
        Node* midNode = findMiddleNode(head);

        Node* left = sortList(head);
        Node* mid = sortList(midNode);

        Node* nh  = merge(left,mid );
        
        return nh;
    }
    
    Node* flattenSort(Node *root) {
        if(!root) return NULL;

        // Create a single unsorted bottom list from all next-bottom chains
        Node* dummy = new Node(-1);
        Node* tail = dummy;
        Node* curr = root;

        while(curr){
            Node* temp = curr;
            while(temp){
                tail->bottom = temp;
                tail = tail->bottom;
                temp = temp->bottom;
            }
            curr = curr->next;
        }

        // Important: Cut off all 'next' pointers to avoid confusion or cycles
        curr = dummy->bottom;
        while(curr){
            curr->next = NULL;
            curr = curr->bottom;
        }

        // Now sort the combined bottom list
        return sortList(dummy->bottom);
    }
    
    Node* flattenIterative(Node *root) {
        
        //  return flattenSort(root);
        Node* curr = root;
        Node* head = root;
    
        while(curr){
            Node* next = curr->next;
            head = merge(head, next);
            curr = next;
        }
        
        curr = head;
        while(curr){
            curr->next = NULL;
            curr = curr->bottom;
        }
        
        return head;
    }
    
    struct mycomp {
    bool operator()(Node* a, Node* b) {
            return a->data > b->data; // min-heap
        }
    };

    Node* flattenMinHeap(Node *root) {
        if (!root) return NULL;
    
        priority_queue<Node*, vector<Node*>, mycomp> pq;
    
        // Push all top-level nodes into the priority queue
        Node* curr = root;
        while (curr) {
            pq.push(curr);
            curr = curr->next;
        }
    
        Node* dummy = new Node(-1);
        Node* tail = dummy;
    
        while (!pq.empty()) {
            
            Node* temp = pq.top();
            pq.pop();
    
            tail->bottom = temp;
            tail = tail->bottom;
    
            if(temp->bottom) {
                pq.push(temp->bottom);
            }
        }
    
        // Clear all 'next' pointers
        curr = dummy->bottom;
        while (curr) {
            curr->next = NULL;
            curr = curr->bottom;
        }
    
        return dummy->bottom;
    }
    
    Node* flatten(Node *root) {
        
        //  return flattenSort(root);
        //  return flattenIterative(root);
        return flattenMinHeap(root);
    }

};
