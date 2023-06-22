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
        cout << node->data; 
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
    Node *rev(Node *head){
        if(head == NULL || head->next == NULL)
            return head;
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
        head = rev(head);
        bool carry = true;
        Node *curr = head;
        while(curr and carry){
            if(curr->next == NULL and curr->data == 9){
                curr->data = 1;
                Node *node = new Node(0);
                node->next = head;
                head = node;
                carry = false;
            }
            else if(curr->data == 9){
                curr->data = 0;
                curr = curr->next;
            }
            else{
                curr->data = curr->data+1;
                carry = false;
            }
        }
        head = rev(head);
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