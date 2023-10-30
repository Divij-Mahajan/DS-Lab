//26. Merge two sorted link list 
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


Node* merge(Node* l1,Node* l2){
    Node* head,*h;
    if(l1->data<l2->data){
        head=new Node(l1->data);
        l1=l1->next;
    }else{
        head=new Node(l2->data);
        l2=l2->next;
    }
    h=head;
    while(l1&&l2){
        Node* temp;
        if(l1->data<l2->data){
            temp=new Node(l1->data);
            l1=l1->next;
        }else{
            temp=new Node(l2->data);
            l2=l2->next;
        }
        head->next=temp;
        head=head->next;
    }
    while(l1){
        Node* temp;
        temp=new Node(l1->data);
        l1=l1->next;        
        head->next=temp;
        head=head->next;
    }
    while(l2){
        Node* temp;
        temp=new Node(l2->data);
        l2=l2->next;        
        head->next=temp;
        head=head->next;
    }
    return h;
}

int main(){
    int a[5]={1,3,5,6,8};
    int b[5]={2,4,6,9,10};
    //creating Lists
    Node* l1=createList(a,5);
    Node* l2=createList(b,5);
    //merge
    showList(l1);
    showList(l2);
    showList(merge(l1,l2));
    return 0;
}