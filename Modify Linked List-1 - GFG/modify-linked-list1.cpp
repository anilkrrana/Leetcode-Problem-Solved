//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
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
class Solution{
    public:
    struct Node* rev(struct Node *head){
        struct Node* prev = NULL;
        struct Node* pres = head;
        struct Node* next = head->next;
        while(pres!=NULL){
            pres->next = prev;
            prev = pres;
            pres = next;
            if(next!=NULL)next=next->next;
        }
        return prev;
    }
    struct Node* modifyTheList(struct Node *head)
    {
        Node* slow = head;
        Node* fast = head;
        Node* mid = head;
        Node* temp = head;
        int len=0;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        while(fast!=NULL and fast->next!=NULL){
            mid=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(len%2==0)mid->next=rev(mid->next);
        else slow->next=rev(slow->next);
        // return head;
        Node* one = head;
        Node* two = len%2==0?mid->next:slow->next;
        while(two!=NULL){
            int temp;
            temp = one->data;
            int op = two -> data;
            int diff = op - temp;
            one->data = diff;
            two->data=temp;
            two=two->next;
            one=one->next;
        }
        if(len%2==0)mid->next = rev(mid->next);
        else slow->next = rev(slow->next);
        return head;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends