//4.insertion and deletion at beginning 
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
    size=n;
}
void Array::insert(int x){
    cout<<"Inserting element "<<x<<" at start"<<endl;
    int i=0;
    if(filled>=size){
        cout<<"Overflow"<<endl;
        return;
    }
    filled++;
    while(i<size){
        int temp=array[i];
        array[i]=x;
        x=temp;
        i++;
    }
}

void Array::del(){
    cout<<"Deleting element at start"<<endl;
    int i=0;
    if(filled<0){
        cout<<"Underflow"<<endl;
        return;
    }
    filled--;
    while(i<size){
        array[i]=array[i+1];
        i++;
    }
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



