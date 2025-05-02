/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode* head) {
        
        if(!head)
            return head;

        ListNode* s=head;
        ListNode* f=head;
        do{
            s = s->next;
            f = f->next;
            if(f){
                f = f->next;
            }
        }while(f && s != f);

        if(!f){
            return f;
        }

        s=head;
        while(s != f){
            s = s->next;
            f = f->next;
        }
        return s;
    }
};