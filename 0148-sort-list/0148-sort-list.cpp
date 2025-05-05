/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* s=head;
        ListNode* f=head;
        ListNode* prev = nullptr;
        while(f != NULL){
            prev = s;
            s = s->next;
            f = f->next;
            if(f)
                f = f->next;
        }
        ListNode* midNode = prev ->next;
        prev->next = NULL;
        ListNode* left = sortList(head);
        ListNode* mid = sortList(midNode);

        ListNode* nh = new ListNode(-1);
        ListNode* nt = nh;

        while(left && mid ){
            if(left->val <= mid->val){
                nt->next = new ListNode(left->val);
                left = left->next;
            }else{
                nt->next = new ListNode(mid->val);
                mid = mid->next;
            }
            nt = nt->next;
        }

        while(left){
            nt->next = new ListNode(left->val);
            left = left->next;
            nt = nt->next;
        }

         while(mid){
            nt->next = new ListNode(mid->val);
            mid = mid->next;
            nt = nt->next;
        }

        return nh->next;
    }
};