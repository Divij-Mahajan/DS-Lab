//54. Creation of bst deletion 
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
    TreeNode* findMin(TreeNode* current) {
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    TreeNode* remove(TreeNode* current, int value) {
        if (current == nullptr) {
            return nullptr;
        }

        if (value < current->data) {
            current->left = remove(current->left, value);
        } else if (value > current->data) {
            current->right = remove(current->right, value);
        } else {
            if (current->left == nullptr) {
                TreeNode* temp = current->right;
                delete current;
                return temp;
            } else if (current->right == nullptr) {
                TreeNode* temp = current->left;
                delete current;
                return temp;
            }

            TreeNode* temp = findMin(current->right);
            current->data = temp->data;
            current->right = remove(current->right, temp->data);
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
    void remove(int value) {
        root = remove(root, value);
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

    int removeValue = 5;
    cout << "Removing " << removeValue <<endl;
    bst.remove(removeValue);
    cout << "Inorder Traversal: ";
    bst.inorderTraversal();

    return 0;
}
