//48. Lowest common ancestor 
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

    BinaryTreeNode* findLCA(BinaryTreeNode* current,  int node1,  int node2)  {
        if (current == nullptr) {
            return nullptr;
        }

        if (current->data == node1 || current->data == node2) {
            return current;
        }

        BinaryTreeNode* leftLCA = findLCA(current->left, node1, node2);
        BinaryTreeNode* rightLCA = findLCA(current->right, node1, node2);

        if (leftLCA != nullptr && rightLCA != nullptr) {
            return current;  
        }

        return (leftLCA != nullptr) ? leftLCA : rightLCA;
    }
    int findLowestCommonAncestor( int node1,  int node2)  {
        BinaryTreeNode* lcaNode = findLCA(root, node1, node2);

        if (lcaNode != nullptr) {
            return lcaNode->data;
        } else {
            cerr << "No common ancestor found." << endl;
            return -1;  
        }
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

    int lcaValue = binaryTree.findLowestCommonAncestor(6, 9);
    cout << "Lowest Common Ancestor of 6 and 9 : " << lcaValue << endl;

    return 0;
}
