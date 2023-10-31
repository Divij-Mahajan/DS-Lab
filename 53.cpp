//53. Creation of binary search tree insertion
#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const int value) : data(value), left(nullptr), right(nullptr) {}
};


class BinarySearchTree {
private:
    TreeNode* root;
    TreeNode* insert(TreeNode* current, const int value) {
        if (current == nullptr) {
            return new TreeNode(value);
        }
        if (value < current->data) {
            current->left = insert(current->left, value);
        } else if (value > current->data) {
            current->right = insert(current->right, value);
        }

        return current;
    }

    void inorderTraversal(TreeNode* current) const {
        if (current != nullptr) {
            inorderTraversal(current->left);
            cout << current->data << " ";
            inorderTraversal(current->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}
    void insert(const int value) {
        root = insert(root, value);
    }
    void inorderTraversal() const {
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    cout << "Inorder Traversal: ";
    bst.inorderTraversal();

    return 0;
}
