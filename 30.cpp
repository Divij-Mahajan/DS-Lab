//30. Stack implementation using link list
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
class StackLL{
  
    Node* head;
    public:
    StackLL(int x){
        head=new Node(x);
    }
    bool isEmpty(){
        return head==NULL;
    }
    int getTop(){
        return head->data;
    }
    void push(int x){
        cout<<"Pushing "<<x<<endl;
        Node* temp=new Node(x);
        temp->next=head;
        head=temp;
    }
    int pop(){
        if(!isEmpty()){
            cout<<"Popping from the head"<<endl;
            Node* temp=head;
            head=head->next;
            int d=temp->data;
            delete temp;
            return d;
        }else{
            cout<<"Stack UnderFlow"<<endl;
        }
    }
};

int main(){
    cout<<"Stack using Linked List"<<endl;
    StackLL* s2=new StackLL(10);//Value of 1st element
    s2->push(2);
    s2->push(0);
    s2->push(-2);
    cout<<s2->pop()<<endl;
    cout<<s2->pop()<<endl;
    cout<<s2->pop()<<endl;
    
   
    return 0;
}