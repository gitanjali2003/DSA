//{ Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
void insertAtTail(Node*&tail,Node*temp)
{
    tail ->next = temp;
    tail = temp;
    
}
Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    Node* head = new Node(-1);
    Node* tail = head;
    
    Node* temp1 = head1;
    Node* temp2 = head2;
    
    while(temp1 != NULL && temp2 != NULL)
    {
        int num1 = temp1->data;
        int num2 = temp2->data;
        
        if(num1 < num2)
        {
            insertAtTail(tail,temp1);
            temp1 = temp1->next;
            
        }
        else 
        {
            insertAtTail(tail,temp2);
            temp2 = temp2->next;
            
        }
    }
    
    while(temp1 != NULL)
    {
        insertAtTail(tail,temp1);
        temp1 = temp1->next;
    }
    while(temp2 != NULL)
    {
        insertAtTail(tail,temp2);
        temp2 = temp2->next;
    }
    
    head = head->next;
    return head;
    
}  