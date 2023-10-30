//28. Program to find Nth node from the end of a link list
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};



Node* findNthFromEnd(Node* head, int n)
{
    Node* ptr1=head,*ptr2=head;
        for(int i=0;i<n;i++){
            ptr2=ptr2->next;

        }
        if(ptr2==nullptr){
            return head->next;
        }
        if(n==1){
            ptr2=ptr2->next;
        }
        while(ptr2!=nullptr){
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return ptr1;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original linked list: ";
    printList(head);

    int n ; // Change N as needed
    cout<<"Enter n :";
    cin>>n;
    Node* nthNode = findNthFromEnd(head, n);

    if (nthNode != nullptr)
        cout << "Nth node from the end: " << nthNode->data << endl;

    return 0;
}