//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    
    Node *reverse(Node *head){
        Node *prev = NULL;
        while(head){
            Node *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        if(head == NULL){
            Node *n = new Node(1);
            return n;
        }
        Node *rev = reverse(head);
        Node *curr = rev;
        int carry = 1;
        Node *prev;
        while(curr){
            prev = curr;
            int a = curr->data+carry;
            curr->data = a%10;
            carry = a/10;
            curr = curr->next;
            if(carry == 0) break;
        }
        if(carry){
            prev->next = new Node(1);
        }
        head = reverse(rev);
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends