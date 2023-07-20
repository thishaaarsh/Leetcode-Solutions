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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        bool isfirst = true;
        ListNode *prevf = NULL;
        ListNode *curr = head;
        while(curr){
            ListNode *first = curr;
            ListNode *prev = NULL;
            int k = 2;
            while(curr and k){
                ListNode *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                k--;
            }
            if(isfirst){
                isfirst = false;
                head = prev;
            }
            else prevf->next = prev;
            prevf = first;
        }
        //prevf->next = curr;
        return head;
    }
};