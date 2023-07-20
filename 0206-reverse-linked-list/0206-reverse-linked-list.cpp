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
    ListNode *rev(ListNode *root, ListNode *prev){
        if(root == NULL) return prev;
        ListNode *next = root->next;
        root->next = prev;
        return rev(next,root);
        
    }
    ListNode* reverseList(ListNode* head) {
        return rev(head,NULL);
    }
};