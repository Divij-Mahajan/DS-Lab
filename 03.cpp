//3.insertion and deletion in array at user defined location

#include <iostream>
using namespace std;

class Array{
    private:
        int * array,size,filled;
    public:
        Array(int n);
        void insert(int i,int x);
        void del(int i);
        void show();
};

Array::Array(int n){
    array=new int[n];
    size=n;
}
void Array::insert(int i,int x){
    cout<<"Inserting "<<x<<" at "<<i<<endl;
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

void Array::del(int i){
    cout<<"Deleting element at "<<i<<endl;
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
    arr->insert(2,34);
    arr->show();
    arr->insert(1,45);
    arr->insert(6,99);
    arr->show();
    arr->del(2);
    arr->show();
    return 0;
}
