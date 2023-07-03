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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *curr = new ListNode(-1);
        ListNode *head = l1;
        curr->next = l1;
        int carry = 0;
        while(l1 and l2){
            curr = curr->next;
            int a = l1->val+l2->val+carry;
            carry = a/10;
            curr->val = a%10;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1!=NULL){
        while(l1){
            curr = curr->next;
            int a = l1->val+carry;
            curr->val = a%10;
            carry = a/10;
            l1 = l1->next;
        }
    }
    if(l2!=NULL){
        while(l2){
            int a = l2->val+carry;
            carry = a/10;
            curr->next = new ListNode(a%10);
            curr = curr->next;
            l2 = l2->next;
        }
    }
    if(carry){
        curr->next = new ListNode(1);
    }
    return head;
    }
    
};