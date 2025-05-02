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
    bool hasCycle(ListNode *head) {
        
        if(!head)
            return 0;

        ListNode * s = head;
        ListNode * f = head;
        do{
            s=s->next;
            f = f->next;
            if(f)
                f = f->next;
        }
        while(f && s != f);

        return s == f && f != NULL;

    }
};