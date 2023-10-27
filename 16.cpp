//16. Link list insertion and deletion at beginning
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
    void insertAtHead(int d);
    void deleteAtHead();
    void show();
};

LL::LL(int d)
{
    head = new SNode;
    tail = head;
    head->data = d;
    cout<<"Inserting "<<d<<" at head."<<endl;
    head->next = NULL;
    num=1;
}

void LL::insertAtHead(int d)
{
    num++;
    cout<<"Inserting "<<d<<" at head."<<endl;
    SNode *temp = new SNode;
    temp->data = d;
    temp->next = head;
    head = temp;
}
void LL::deleteAtHead()
{
    if(num==0){
        cout<<"Underflow"<<endl;
        return ;
    }
    cout<<"Deleting element at head"<<endl;
    SNode* temp=head;
    head=head->next;
    num--;
    delete temp;
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

    list->insertAtHead(5);
    list->insertAtHead(2);
    list->show();
    list->deleteAtHead();
    list->show();
    list->show();
    return 0;
}