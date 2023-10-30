//32. Queue implementation using link list
#include <iostream>
#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int x){
            data=x;
            next=NULL;
        }
};


class QueueLL{
    Node* head,*tail;
    public:
    QueueLL(int x){
        head=new Node(x);
        tail=head;
        cout<<"Enqueued "<<x<<endl;
    }
    bool isEmpty(){
        return head==tail;
    }
    int getTop(){
        return head->data;
    }
    void enqueue(int x){
        Node* temp=new Node(x);
        tail->next=temp;
        cout<<"Enqueued "<<x<<endl;
            
        tail=tail->next;
    }
    int dequeue(){
        if(!isEmpty()){
            Node* temp=head;
            head=head->next;
            int d=temp->data;
            cout<<"Dequeuing from the Queue"<<endl;
            delete temp;
            return d;
        }else{
            cout<<"Queue UnderFlow"<<endl;
        }
    }
};

int main(){
    cout<<"Queue using Linked List"<<endl;
    QueueLL* q2=new QueueLL(10);// Value of 1st Element
    q2->enqueue(2);
    q2->enqueue(0);
    q2->enqueue(-2);
    cout<<q2->dequeue()<<endl;
    cout<<q2->dequeue()<<endl;
    cout<<q2->dequeue()<<endl;
    return 0;
}