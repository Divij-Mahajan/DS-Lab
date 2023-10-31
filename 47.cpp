//47. Diameter of binary tree
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
    int height(BinaryTreeNode* current) const {
        if (current == nullptr) {
            return 0;
        } else {
            int leftHeight = height(current->left);
            int rightHeight = height(current->right);
            return 1 + max(leftHeight, rightHeight);
        }
    }
    int diameter(BinaryTreeNode* current) const {
        if (current == nullptr) {
            return 0;
        }

        int leftDiameter = diameter(current->left);
        int rightDiameter = diameter(current->right);

        return max(max(leftDiameter, rightDiameter), height(current->left) + height(current->right) + 1);
    }

    int diameter() const {
        return diameter(root);
    }
    void levelorderTransversal(){
        queue<BinaryTreeNode*> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty()) {
            BinaryTreeNode* current;
            if(q.front()){
                current = q.front();
            }else{
                cout<<endl;
                q.pop();
                if(!q.empty()){
                    q.push(NULL);
                }
                continue;
            }
            q.pop();
            cout<<current->data<<" ";
            if (current->left != nullptr){
                q.push(current->left);
            }

            if (current->right != nullptr){
                q.push(current->right);
            }

        }
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
    cout << "Level Order Traversal: "<<endl;
    binaryTree.levelorderTransversal();

    int treeDiameter = binaryTree.diameter();
    cout << "Diameter of the tree: " << treeDiameter << endl;

    return 0;
}
