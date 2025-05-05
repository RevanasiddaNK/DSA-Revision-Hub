/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        unordered_map<Node*, Node*>mp;
        Node* cloneHead = new Node(head->val);
        mp[head] = cloneHead;
        Node* tail = head->next;
        Node* ctail = cloneHead;
        while(tail){
            ctail->next = new Node(tail->val);
            ctail = ctail->next;
            mp[tail] = ctail;
            tail = tail->next; 
        }
        mp[NULL] = NULL;

        ctail = cloneHead;
        tail = head;
        while(tail){
            ctail->random = mp[tail->random];
            ctail =  ctail->next;
            tail = tail->next;
        }
        return cloneHead;
    }
};