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
    ListNode *merge(ListNode *l1, ListNode *l2){
        ListNode *temp = new ListNode(-1);
        ListNode *curr = temp;
        while(l1 and l2){
            if(l1->val <= l2->val){
                curr->next = l1;
                l1 = l1->next;
            }
            else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr =  curr->next;
        }
        if(l1){
            curr->next = l1;
        }
        if(l2){
            curr->next = l2;
        }
        return temp->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *next = slow->next;
        slow->next = NULL;
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(next);
        return merge(l1,l2);
    }
};