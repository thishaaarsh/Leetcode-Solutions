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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *os=NULL,*oe=NULL,*es=NULL,*ee=NULL;
        ListNode *curr = head;
        int i=0;
        for(;curr!=NULL;curr=curr->next,i++){
            //int x = curr->val;
            if(i%2){
                if(os == NULL){
                    os = curr;
                    oe = curr;
                }
                else{
                    oe->next = curr;
                    oe = oe->next;
                }
            }
            else{
                if(es == NULL){
                    es = curr;
                    ee = curr;
                }else{
                    ee->next = curr;
                    ee = ee->next;
                }
            }
        }
        if(os==NULL || es == NULL) return head;
        else{
            ee->next = os;
            oe->next = NULL;
            return es;
        }
    }
};