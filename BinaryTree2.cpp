#include <iostream>
#include <iomanip> 
#define NAUP std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)

struct Node {
    int value;     
    Node* left;       
    Node* right;       

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BSTree {
private:
    Node* root;

    Node* insertNode(Node* node, int value) {
        if (!node) return new Node(value);

        if (value < node->value) {
            node->left = insertNode(node->left, value);
        } else if (value > node->value) {
            node->right = insertNode(node->right, value);
        }
        
        return node;
    }
    
    Node* findMin(Node* node) {
        while (node->left) node = node->left;
        return node;
    }
    
    Node* deleteNode(Node* node, int value) {
        if (!node) return nullptr;

        if (value < node->value) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->value) {
            node->right = deleteNode(node->right, value);
        } else {
            if (!node->left || !node->right) {
                Node* temp = node->left ? node->left : node->right;
                delete node;
                return temp;
            } else {
                Node* minNode = findMin(node->right);
                node->value = minNode->value;
                node->right = deleteNode(node->right, minNode->value);
            }
        }
        return node;
    }

    void printNodeInfo(Node* node) {
        if (!node) return;

        printNodeInfo(node->left);
        std::cout << "Value: " << node->value
             << ", Left: " << (node->left ? std::to_string(node->left->value) : "NULL")
             << ", Right: " << (node->right ? std::to_string(node->right->value) : "NULL")
             << std::endl;
        printNodeInfo(node->right);
    }
    
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        std::cout << node->value << " ";
        inorder(node->right);
    }
    
    void preorder(Node* node) {
        if (node == nullptr) return;
        std::cout << node->value << " "; 
        preorder(node->left);
        preorder(node->right);
    }

public:
    BSTree() : root(nullptr) {}

    void insert(int value) {
        root = insertNode(root, value);
    }
    
    void Remove(int value) {
        root = deleteNode(root, value);
    }

    void printTreeInfo() {
        printNodeInfo(root);
    }
    
    void printInOrder() {
        inorder(root);
    }
    
    void printPreOrder() {
        preorder(root);
    }
};

int main() {
    NAUP;
    
    BSTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(7);

 
    tree.printInOrder();
    return 0;
}
