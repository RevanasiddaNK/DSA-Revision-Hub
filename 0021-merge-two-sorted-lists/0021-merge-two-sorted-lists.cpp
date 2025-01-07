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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* h = new ListNode(0);
        ListNode* head = h;
        ListNode* h1 = list1;
        ListNode* h2 = list2;

        while(h1 != NULL && h2 != NULL){
            if(h1->val <= h2->val){
                h->next = h1;
                h1 = h1->next; 
            }
            else{ 
                h->next = h2;
                h2 = h2->next; 
            }
            h = h->next;
        }

        if(h1 != NULL){
            h->next = h1;
        }

       if(h2 != NULL){
            h->next = h2;
        }

        return  head->next;
    }
};