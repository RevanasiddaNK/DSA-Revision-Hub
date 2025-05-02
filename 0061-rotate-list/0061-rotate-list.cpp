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
        int n=0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            n++;
        }
        k = k%n;

        if(k==0)
            return head;

        ListNode* th1=head;
        ListNode* th2=head;
        while(k >0){
            th1 = th1->next;
            k--;
        }
        

        while(th1->next){
            th1 = th1->next;
            th2 = th2->next;
        }
        ListNode* nh=th2->next;
        th2->next = NULL;
        th1->next = head;


        return nh;
    }
};