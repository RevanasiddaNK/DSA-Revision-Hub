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
        if( (!head   || ! head->next) )
            return head;

        int n=0;
        ListNode* curr = head;
        while(curr){
            n++;
            curr = curr->next;
        }
        k = k%n;

        if(k == 0) 
            return head; 

        ListNode* temp = head;
        for(int i=0; i<k; i++){
            temp = temp->next;
        }

        curr = head;
        while(temp->next){
            curr = curr->next;
            temp = temp->next;
        }

        ListNode* nh =  curr->next;
        curr->next = NULL;
        temp->next = head;
        
        return nh;
    }
};