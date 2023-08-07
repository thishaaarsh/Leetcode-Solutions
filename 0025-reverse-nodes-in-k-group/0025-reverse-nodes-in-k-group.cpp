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
    ListNode *revink(ListNode *head, int count, int k){
        if(count < k || head == NULL) return head;
        ListNode *curr = head;
        ListNode *prev = NULL;
        int p = k;
        while(curr and p){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            p--;
        }
        head->next = revink(curr,count-k, k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode *curr = head;
        while(curr){
            count++;
            curr = curr->next;
        }
        return revink(head,count,k);
    }
};