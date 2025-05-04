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

    ListNode* reverseKGroupIterativeMethod(ListNode* head, int k) {
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

    ListNode* recSol(ListNode* head, int k){
        if(!head){
            return head;
        }
        
        ListNode* check = head;
        int cnt = 0;
        while(check && cnt < k){
            check = check->next;
            cnt++;
        }
        if(cnt < k)
            return head;
        
        // revrse k nodes
        ListNode* curr = head;
        ListNode* next = head->next;
        ListNode* prev = NULL;
        cnt = 0;
        while(curr && cnt < k){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        head->next = recSol(curr, k);
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        //return reverseKGroupIterativeMethod(head,k);
        return recSol(head,k);
    }
};