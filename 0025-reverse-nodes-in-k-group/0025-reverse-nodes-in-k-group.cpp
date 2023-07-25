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
    ListNode *revinK(ListNode *head, int count, int k){
        if(head == NULL || count < k) return head;
        ListNode *curr = head;
        ListNode *prev = NULL;
        int c = 0;
        while(curr and c<k){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            c++;
        }
        if(curr!=NULL){
            head->next = revinK(curr,count-k,k);
        }
        return prev;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count =0;
        ListNode *curr = head;
        while(curr){
            count++;
            curr = curr->next;
        }
        return revinK(head,count,k);
    }
};