//44. Post order traversal
#include <iostream>
#include <queue>
using namespace std;

struct BinaryTreeNode {
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode( int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    BinaryTreeNode* root;

public:
    BinaryTree() : root(nullptr) {}
    void insert( int value) {
        BinaryTreeNode* newNode = new BinaryTreeNode(value);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        queue<BinaryTreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            BinaryTreeNode* current = q.front();
            q.pop();

            if (current->left == nullptr) {
                current->left = newNode;
                return;
            } else {
                q.push(current->left);
            }

            if (current->right == nullptr) {
                current->right = newNode;
                return;
            } else {
                q.push(current->right);
            }
        }
    }
    void postorderTraversal(BinaryTreeNode* current) const {
        if (current != nullptr) {
            postorderTraversal(current->left);
            postorderTraversal(current->right);
            cout << current->data << " ";
        }
    }

    void postorderTraversal() const {
        postorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinaryTree binaryTree;
    binaryTree.insert(1);
    binaryTree.insert(2);
    binaryTree.insert(3);
    binaryTree.insert(4);
    binaryTree.insert(5);
    binaryTree.insert(6);
    binaryTree.insert(7);
    binaryTree.insert(8);
    binaryTree.insert(9);

    cout << "Postorder Traversal: "<<endl;
    binaryTree.postorderTraversal();

    return 0;
}
