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

    bool isPalindromeUsingArr(ListNode* head) {
        vector<int>arr;

        ListNode* curr = head;
        while(curr){
            arr.push_back(curr->val);
            curr = curr->next;
        }

        int s=0, e=arr.size()-1;
        while(s<=e){
            if(arr[s++] != arr[e--]){
                return 0;
            }
        }
        return 1;
    }

    bool isPalindromeStack(ListNode* head){
        stack<int>st;
        ListNode* curr = head;

        while(curr){
            st.push(curr->val);
            curr = curr->next;
        }

        curr = head;

        while(curr){
            int f = st.top();
            st.pop();
            if(f != curr->val ){
                return 0;
            }
            curr = curr->next;
        }
        return 1;
    }

    bool isPalindrome(ListNode* head){
        //  return isPalindromeUsingArr(head);
        return isPalindromeStack(head);

    }
};