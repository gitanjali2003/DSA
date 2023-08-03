//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    void insertAtTail(Node*&tail,Node*temp)
    {
        tail ->next = temp;
        tail = temp;
    
    }
    Node* merge(Node* head1,Node* head2)
    {
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
    
//      Node* solve(Node* head1, Node* head2)
// {
//     if(head1 ->next == NULL)
//     {
//         head1->next = head2;
//         return head1;
//     }
//     Node* curr1 = head1;
//     Node* next1 = head1->next;
//     Node* curr2 = head2;
//     Node* next2 = head2->next;
 
 
    
//     while(next1 != NULL && curr2 != NULL)
//     {
        
//         if((curr2->data >= curr1->data) && (curr2->data <= next1->data))
//         {
//             curr1->next = curr2;
//             next2 = curr2->next;
//             curr2->next = next1;
            
//             curr1 = curr2;
//             curr2 = next2;
            
//         }
//         else
//         {
//             curr1 = curr1->next;
//             next1 = next1->next;
            
//             if(next1 == NULL)
//             {
//                 curr1->next = curr2;
//                 return head1;
//             }
//         }
        
//     }
    
    
//     return head1;
// }

// Node* merge(Node* head1, Node* head2)  
// {  
//     // code here
    
//     if(head1->data >= head2->data)
//     {
//         return solve(head2,head1);
        
//     }
//     else
//     {
//         return solve(head1,head2);
        
//     }
    
// }   
    Node* findMid(Node* head)
    {
        Node*slow = head;
        Node*fast = head->next;
        
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
        
            
    }
    Node* mergeSort(Node* head) {
        
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        Node*mid = findMid(head);
        Node*left = head;
        Node*right = mid->next;
        mid->next = NULL;
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        return merge(left,right);
        
        
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends