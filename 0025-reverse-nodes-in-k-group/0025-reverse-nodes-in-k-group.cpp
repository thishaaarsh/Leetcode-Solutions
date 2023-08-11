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
    ListNode *solve(ListNode *head,int k,int count){
        if(head == NULL || count < k) return head;
        ListNode *prev = NULL;
        ListNode *curr = head;
        int a = k;
        while(curr and a--){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = solve(curr,k,count-k);
        return prev;
        
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head;
        int count = 0;
        while(curr){
            curr = curr->next;
            count++;
        }
        return solve(head,k,count);
    }
};