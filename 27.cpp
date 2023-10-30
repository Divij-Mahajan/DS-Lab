//27.check if link list is palindrome or not
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void showList(Node* head){
    while(head){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}

bool isPalindrome(Node* head) {
    if (!head || !head->next) {
        return true; 
    }

    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* reversedSecondHalf = reverseList(slow);
    Node* firstHalf = head;
    while (reversedSecondHalf) {
        if (firstHalf->data != reversedSecondHalf->data) {
            return false; 
        }
        firstHalf = firstHalf->next;
        reversedSecondHalf = reversedSecondHalf->next;
    }

    return true; 
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    showList(head);
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
