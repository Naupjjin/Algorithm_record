#include <bits/stdc++.h>
#define mp std::make_pair
#define pr std::pair<int, int>
#define ll long long
#define NAUP std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)

struct Node {
    int data;           // Node value
    Node* left;         // left node
    Node* right;        // right node
    Node* parent;       // parent node

    // node constructor
    Node(int data) 
        : data(data), left(nullptr), right(nullptr), parent(nullptr) {
        
        }
};


struct BinaryTree{
    
    Node* root; 
    BinaryTree(Node* root) : root(root) {}
    
        void insert(int value) {
        Node* newNode = new Node(value);
        Node* current = root;
        Node* parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (value < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        newNode->parent = parent;
        if (parent == nullptr) {
            root = newNode;
        } else if (value < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }

    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }

    void printInOrder() {
        inorder(root);
    }
};

int main() {
    NAUP;

    Node* root = new Node(10);

    BinaryTree tree(root);

    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    tree.printInOrder(); 

}