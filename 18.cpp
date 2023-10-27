//18. Link list insertion and deletion at a position 
#include <iostream>
using namespace std;

class SNode
{
public:
    int data;
    SNode *next;
};
class LL
{
    SNode *head;
    int num;

public:
    LL(int d);
    void insert(int i,int d);
    void del(int i);
    void show();
};

LL::LL(int d)
{
    head = new SNode;
    
    head->data = d;
    cout<<"Inserting "<<d<<" at head."<<endl;
    head->next = NULL;
    num=1;
}


void LL::insert(int i,int d)
{
    num++;
    SNode *temp = new SNode;
    cout<<"Inserting "<<d<<" at "<<i<<endl;
    SNode* t = head;
    while(i>1){
        t=t->next;
        i--;
    }
    temp->data = d;
    temp->next = t->next;
    t->next = temp;
}
void LL::del(int i){
    if(num==0){
        cout<<"Underflow"<<endl;
        return ;
    }
    cout<<"deleting at "<<i<<endl;
    num--;
    SNode *temp = head;
    while (i>1)
    {
        temp = temp->next;
        i--;
    }
    SNode *t=temp->next;
    temp->next=temp->next->next;
    delete t;
}

void LL::show()
{
    SNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    LL *list = new LL(3);
    list->insert(1,7);
    list->insert(1,10);
    list->show();
    list->del(1);
    list->show();
    return 0;
}
