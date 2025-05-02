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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* r1 = l1;
        ListNode* r2 = l2;

        int carry = 0;

        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        while( r1 && r2){
            int sum = r1->val + r2->val + carry;
            carry = sum / 10;
            int digit = sum % 10;
            curr->next = new  ListNode(digit);
            curr = curr->next;
            r1 = r1->next;
            r2 = r2->next;
        }

        while(r1){
            int sum = r1->val + carry;
            carry = sum / 10;
            int digit = sum % 10;
            curr->next = new  ListNode(digit);
            curr = curr->next;
            r1 = r1->next;
        }

        while(r2){
            int sum = r2->val + carry;
            carry = sum / 10;
            int digit = sum % 10;
            curr->next = new  ListNode(digit);
            curr = curr->next;
            r2 = r2->next;
        }

        if(carry != 0){
            curr->next = new  ListNode(carry%10);
            curr = curr->next;
            carry /= 10;
        }

        return head->next;

    }
};