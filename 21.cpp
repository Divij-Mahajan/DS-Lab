//21. Merge point of two given link list
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

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    int n=0,m=0;
    Node* h1=firstHead,*h2=secondHead;
    while(h1){
        h1=h1->next;
        n++;
    }
    while(h2){
        h2=h2->next;
        m++;
    }
    if(m>n){
        int i=0;
        while(i<m-n){
            secondHead=secondHead->next;
            i++;
        }
    }else{
        int i=0;
        while(i<n-m){
            firstHead=firstHead->next;
            i++;
        }
    }
    while(secondHead!=firstHead){
        secondHead=secondHead->next;
        firstHead=firstHead->next;
    }
    return secondHead;
}


int main(){
    int a[4]={3,4,5,6};
    int b[5]={1,2,3,4,5};
    Node* head1=createList(a,4);
    Node* head2=createList(b,5);
    //merging at 3
    Node* t=head1;
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=head2->next->next;

    cout<<findIntersection(head1,head2)->data<<endl;
    return 0;
}