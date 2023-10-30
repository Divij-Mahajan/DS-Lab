//29. Stack implementation using array.
#include <iostream>
using namespace std;
class StackArray{
    int* a,capacity,top;
    public:
    StackArray(int n){
        capacity=n;
        a=new int[n];
        top=0;
    }
    bool isEmpty(){
        return top==0;
    }
    bool isFull(){
        return top==capacity-1;
    }
    int getTop(){
        return a[top];
    }
    void push(int x){
        if(!isFull()){
            a[top]=x;
            cout<<"Pushing "<<x<<endl;
            top++;
        }else{
            cout<<"Stack OverFlow"<<endl;
        }
    }
    int pop(){
        if(!isEmpty()){
            int d=a[top-1];
            a[top-1]=0;
            top--;
            cout<<"Popping from the head"<<endl;
            return d;
        }else{
            cout<<"Stack UnderFlow"<<endl;
        }
    }
};

int main(){
    cout<<"Stack using Array"<<endl;
    StackArray* s1=new StackArray(10);//Size of Stack
    s1->push(23);
    s1->push(4);
    s1->push(1);
    cout<<s1->pop()<<endl;
    cout<<s1->pop()<<endl;
    cout<<s1->pop()<<endl;
    return 0;
}