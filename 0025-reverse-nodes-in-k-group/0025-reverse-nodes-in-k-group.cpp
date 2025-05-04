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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* nh = NULL;
        ListNode* curr = head;
        ListNode* tail = NULL;
        while(curr){
            ListNode* check = curr;
            int count = 0;
    
            while (check && count < k) {
                check = check->next;
                count++;
            }

            if (count < k) {
                if (tail) tail->next = curr;
                break;
            }

            ListNode* grphead = curr;
            int cnt = 0;
            ListNode* prev = NULL;
            while(curr && cnt < k ){
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                cnt++;
            }

           
            
            if(!nh){
                nh = prev;
            }

            if(tail){
                tail->next = prev;
            }
            tail = grphead;
        }
        return nh;
    }
};