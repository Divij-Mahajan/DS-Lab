//20. Link list reversing II
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
    return head;
}

void showList(Node* head){
    while(head){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}

Node* reverseLinkedList(Node *head)
{
    Node * p=nullptr;
    Node * n=nullptr;
    while(head){
        n=head->next;
        head->next=p;
        p=head;
        head=n;
    }
    return p;

}


int main(){
    int b[5]={1,2,3,4,5};
    Node* head=createList(b,5);
    showList(reverseLinkedList(head));
    return 0;
}