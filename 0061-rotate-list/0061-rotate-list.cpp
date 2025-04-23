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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0)
            return head;
        if(!head->next)
            return head;
            
        ListNode* th=head;
        ListNode* tt=head;
        while(k >0){
            ListNode* prev = tt;
            while(tt->next){
                prev = tt;
                tt = tt->next;
            }
            prev->next = NULL;
            tt->next = th;
            th = tt;
            tt= th;
            k--;
        }
        return th;
    }
};