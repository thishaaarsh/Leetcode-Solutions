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
    ListNode *rev(ListNode* head, int k,int count){
        if(count < k) return head;
        ListNode *curr = head,*next =NULL,*prev=NULL;
        int c = 0;
        while(c<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            c++;
        }
        if(next != NULL){
            ListNode *reshead = rev(next,k,count-k);
            head->next = reshead;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head;
        int count = 0;
        while(curr){
            count++;
            curr = curr->next;
        }
        return rev(head,k,count);
    }
};