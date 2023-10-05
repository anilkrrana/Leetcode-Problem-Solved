//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
      Node *reverse(Node *root){

        Node *prev=NULL,*curr=root;

        while(curr!=NULL){

            Node *forw=curr->next;

            curr->next=prev;

            prev=curr;

            curr=forw;

        }

        return prev;  

    }

    

    void rearrange(struct Node *odd)

    {

        Node *temp1=odd,*temp2=odd->next,*temp3=odd->next;

        while(temp1->next!=NULL && temp2->next!=NULL&&temp1!=NULL&&temp2!=NULL){

            temp1->next=temp2->next;

            temp1=temp1->next;

            temp2->next=temp1->next;

            temp2=temp2->next;

        }

        Node *x=reverse(temp3);

        temp1->next=x;

        

    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends