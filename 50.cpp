//50. Bottom view of binary tree
#include <iostream>
#include <queue>
#include <map>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

public:
    BinaryTree() : root(nullptr) {}
    void insert( int value) {
        TreeNode* newNode = new TreeNode(value);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
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
    void levelorderTransversal(){
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty()) {
            TreeNode* current;
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
    void bottomView() {
        if (root == nullptr) {
            return;
        }

        queue<pair<TreeNode*, int> > q;
        map<int, int> bottomViewMap;

        q.push(make_pair(root, 0));

        while (!q.empty()) {
            TreeNode* current = q.front().first;
            int horizontalDistance = q.front().second;
            q.pop();

            bottomViewMap[horizontalDistance] = current->data;

            if (current->left) {
                q.push(make_pair(current->left, horizontalDistance - 1));
            }

            if (current->right) {
                q.push(make_pair(current->right, horizontalDistance + 1));
            }
        }

        cout << "Bottom view of the binary tree: ";
        for (const auto& pair : bottomViewMap) {
            cout << pair.second << " ";
        }
        cout << endl;
    }

    
};

int main() {
    BinaryTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);

    cout<<"Level Order Transversal :"<<endl;
    tree.levelorderTransversal();

    tree.bottomView();

    return 0;
}
