//5.insertion and deletion at end(Specify overflow and underflow)
#include <iostream>
using namespace std;

class Array
{
private:
    int * array,size,filled;
public:
    Array(int n);
    void insert(int x);
    void del();
    void show();
};

Array::Array(int n){
    array=new int[n];
    filled=0;
    size=n;
}
void Array::insert(int x){
    cout<<"Inserting element "<<x<<" at end"<<endl;
    if(filled>=size){
        cout<<"Overflow"<<endl;
        return;
    }
    int i=filled;
    filled++;
    
    while(i<size){
        int temp=array[i];
        array[i]=x;
        x=temp;
        i++;
    }
}

void Array::del(){
    cout<<"Deleting element at end"<<endl;
    if(filled<0){
        cout<<"Underflow"<<endl;
        return;
    }
    int i=filled;
    while(i<size){
        array[i]=array[i+1];
        i++;
    }
    filled--;
}

void Array::show(){
    for (int i = 0; i < size; i++)
    {
        cout<<array[i]<<", ";
    }
    cout<<endl;
    
}



int main(){
    int n=10;
    Array *arr =new Array(n);
    arr->insert(34);
    arr->show();
    arr->insert(45);
    arr->insert(99);
    arr->show();
    arr->del();
    arr->show();
    return 0;
}



