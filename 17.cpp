//17. Link list insertion and deletion at end
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
    SNode *tail;
    int num;

public:
    LL(int d);
    void insertAtTail(int d);
    void deleteAtTail();
    void show();
};

LL::LL(int d)
{
    head = new SNode;
    tail = head;
    head->data = d;
    cout<<"Inserting "<<d<<" at tail."<<endl;
    head->next = NULL;
    num=1;
}


void LL::insertAtTail(int d)
{
    num++;
    SNode *temp = new SNode;
    cout<<"Inserting "<<d<<" at tail."<<endl;
    temp->data = d;
    temp->next = NULL;
    tail->next = temp;
    tail = tail->next;
}
void LL::deleteAtTail(){
    if(num==0){
        cout<<"Underflow"<<endl;
        return ;
    }
    cout<<"deleting from tail"<<endl;
    num--;
    SNode *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    tail=temp;
    temp=temp->next;
    delete temp;
    tail->next=NULL;
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
    list->insertAtTail(7);
    list->insertAtTail(10);
    list->show();
    list->deleteAtTail();
    list->show();
    return 0;
}