//25. Find middle element of link list in o(n) time
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

Node* findMiddle(Node* head) {
    if (!head || !head->next) {
        return head; 
    }

    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
void display(Node * head){
    Node* temp = head;

    if (head) { 
        while (temp->next!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    } else {
        cout << "Empty List" << endl;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    display(head);
    cout << "Middle element: " << findMiddle(head)->data << endl;

    return 0;
}


