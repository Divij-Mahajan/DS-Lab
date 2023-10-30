//31. Queue implementation using array 
#include <iostream>
#include <iostream>
using namespace std;

class QueueArray{
    int* a,capacity,top,end;
    public:
    QueueArray(int n){
        capacity=n;
        a=new int[n];
        top=0;
        end=0;
    }
    bool isEmpty(){
        return top==end;
    }
    bool isFull(){
        return (end+1)%capacity==top;
    }
    int getTop(){
        return a[top];
    }
    void enqueue(int x){
        if(!isFull()){
            a[end]=x;
            end++;
            end=end%capacity;
            cout<<"Enqueued "<<x<<endl;
        }else{
            cout<<"Queue OverFlow"<<endl;
        }
    }
    int dequeue(){
        if(!isEmpty()){
            int d=a[top];
            a[top]=0;
            top++;
            top=top%capacity;
            cout<<"Dequeuing from the Queue"<<endl;
            return d;
        }else{
            cout<<"Queue UnderFlow"<<endl;
        }
    }
};


int main(){
    cout<<"Queue using Array"<<endl;
    QueueArray* q1=new QueueArray(10);//Size of Queue
    q1->enqueue(23);
    q1->enqueue(4);
    q1->enqueue(1);
    cout<<q1->dequeue()<<endl;
    cout<<q1->dequeue()<<endl;
    cout<<q1->dequeue()<<endl;
    
    return 0;
}