/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *solve(ListNode *headA, ListNode *headB,int n){
        for(int i=0; i<n; i++){
            headA = headA->next;
        }
        while(headA!=headB){
            headA=headA->next;
            headB = headB->next;
        }
        return headA;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1=0, n2=0;
        ListNode *curr1 = headA, *curr2 = headB;
        while(curr1){
            curr1 = curr1->next;
            n1++;
        }
        while(curr2){
            curr2 = curr2->next;
            n2++;
        }
        if(n1>n2){
            return solve(headA,headB,n1-n2);
        }
        else{
            return solve(headB,headA,n2-n1);
        }
    }
};