/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        Node *curr = head;
        while(curr){
            Node *next = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = next;
            curr = next;
        }
        curr = head;
        while(curr and curr->next){
            curr->next->random = curr->random ? curr->random->next : NULL;
            curr = curr->next->next;
        }
        Node *ori = head, *clone = head->next;
        Node *ans = clone;
        while(ori and clone){
            ori->next = ori->next ? ori->next->next:NULL;
            clone->next = clone->next ? clone->next->next : NULL;
            ori  = ori->next;
            clone = clone->next;
        }
        return ans;
    }
};