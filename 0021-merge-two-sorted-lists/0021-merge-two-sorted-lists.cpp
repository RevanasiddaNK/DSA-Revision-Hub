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
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        while(curr1 && curr2){

            if(curr1->val <= curr2->val){
                curr->next = new ListNode(curr1->val);
                curr = curr->next;
                curr1 = curr1->next;
            }
            else{
                curr->next = new ListNode(curr2->val);
                curr = curr->next;
                curr2 = curr2->next;
            }
        }

        while(curr1){
            curr->next = new ListNode(curr1->val);
            curr = curr->next;
            curr1 = curr1->next;
        }

        while(curr2){
            curr->next = new ListNode(curr2->val);
            curr = curr->next;
            curr2 = curr2->next;
        }
        return head->next;
    }
};