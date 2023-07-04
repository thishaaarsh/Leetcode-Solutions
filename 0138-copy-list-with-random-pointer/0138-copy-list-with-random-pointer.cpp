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
        unordered_map<Node*,Node*>mp;
        Node *curr = head;
        while(curr){
            Node* next = curr->next;
            mp[curr] = new Node(curr->val);
            curr = next;
        }
        Node *clone;
        curr = head;
        for(;curr!=NULL;curr=curr->next){
            clone = mp[curr];
            clone->next = mp[curr->next];
            clone->random = mp[curr->random];
        }
        Node *h = mp[head];
        return h;
    }
};