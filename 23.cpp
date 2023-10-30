//23. Implement circular link list
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    void insert(int data) {
        Node* newNode = new Node(data);

        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void display() {
        Node* temp = head;

        if (head) { 
            while (temp->next!=head){
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<temp->data<<endl;
        } else {
            cout << "Empty List" << endl;
        }
    }
};

int main() {
    CircularLinkedList myList;

    myList.insert(1);
    myList.insert(2);
    myList.display();
    myList.insert(3);
    myList.insert(4);
    myList.insert(5);
    myList.display();

    return 0;
}
