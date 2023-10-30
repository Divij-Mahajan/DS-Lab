//24. Implement doubly link list
#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void append(int data) {
        Node* newNode = new Node(data);

        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void displayForward() {
        Node* temp = head;

        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }

        cout << "nullptr" << endl;
    }

    void displayBackward() {
        Node* temp = tail;

        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }

        cout << "nullptr" << endl;
    }
};

int main() {
    DoublyLinkedList myList;

    myList.append(1);
    myList.append(2);
    myList.append(3);
    myList.append(4);

    cout << "Doubly Linked List Forward: ";
    myList.displayForward();

    cout << "Doubly Linked List Backward: ";
    myList.displayBackward();

    return 0;
}
