//38. Implement queue using stack
#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStack {
private:
    stack<int> stack1;  
    stack<int> stack2;  

public:
    void enqueue(const int& element) {
        stack1.push(element);
    }
    int dequeue() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        if (stack2.empty()) {
            cerr << "Queue is empty." << endl;
            return -1;  
        }

        int frontElement = stack2.top();
        stack2.pop();

        if (stack1.empty()) {
            while (!stack2.empty()) {
                stack1.push(stack2.top());
                stack2.pop();
            }
        }

        return frontElement;
    }

    bool isEmpty() const {
        return stack1.empty() && stack2.empty();
    }

    size_t size() const {
        return stack1.size() + stack2.size();
    }
};

int main() {
    QueueUsingStack myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    cout << "Dequeued: " << myQueue.dequeue() << endl;
    cout << "Dequeued: " << myQueue.dequeue() << endl;
    myQueue.enqueue(4);
    myQueue.enqueue(5);

    while (!myQueue.isEmpty()) {
        cout << "Dequeued: " << myQueue.dequeue() << endl;
    }

    return 0;
}