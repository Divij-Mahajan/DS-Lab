//22. Link list cycle detection and removal
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
};


Node* createList(int a[],int n){
    Node* head=new Node(a[0]);
    Node* t=head;
    for (int i = 1; i < n; i++){
        Node* temp=new Node(a[i]);        
        t->next=temp;
        t=t->next;
    }
    t->next=head;//loop
    return head;
}

void showList(Node* head){
    while(head){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
bool detectCycle(Node *head)
{
	Node* fast=head,*slow=head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return 1;
            }
        }
        return 0;
}
Node* firstNode(Node *head)
{
    Node* fast=head,*slow=head;
    bool detect=false;
        while(fast->next != NULL && fast->next->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                detect=true;
                break;
            }
        }
        if(!detect){
            return NULL;
        }
    slow=head;
    while(fast!=slow){
            slow=slow->next;
            fast=fast->next;
        }
    return fast;
}

void removeCycle(Node* head){
    Node* first=firstNode(head);
    Node* temp=first;
    while(temp->next!=first){
        temp=temp->next;
    }
    temp->next=NULL;
}

int main(){
    int b[8]={1,2,3,4,5,6,7,8};
    Node* head=createList(b,8);
    cout<<"Cycle present :"<<detectCycle(head)<<endl;
    removeCycle(head);
    cout<<"Cycle present :"<<detectCycle(head)<<endl;
    showList(head);
    
    return 0;
}
