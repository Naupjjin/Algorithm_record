#include <iostream>
#include <iomanip> 
#define NAUP std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)

struct Node {
    int value;     
    int height;        
    Node* left;       
    Node* right;       

    Node(int val) : value(val), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    Node* root;

    int getHeight(Node* node) {
        return node ? node->height : 0;
    }
    
    int getBalanceFactor(Node* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    void updateHeight(Node* node) {
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T = x->right;

        x->right = y;
        y->left = T;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T = y->left;

        y->left = x;
        x->right = T;

        updateHeight(x);
        updateHeight(y);

        return y;
    }


    Node* balance(Node* node) {
        updateHeight(node);
        int balanceFactor = getBalanceFactor(node);

        if (balanceFactor > 1) {
            if (getBalanceFactor(node->left) < 0) {
                node->left = rotateLeft(node->left);
            }
            return rotateRight(node);
        }

        if (balanceFactor < -1) {
            if (getBalanceFactor(node->right) > 0) {
                node->right = rotateRight(node->right);
            }
            return rotateLeft(node);
        }

        return node;
    }

    Node* insertNode(Node* node, int value) {
        if (!node) return new Node(value);

        if (value < node->value) {
            node->left = insertNode(node->left, value);
        } else if (value > node->value) {
            node->right = insertNode(node->right, value);
        } else {
            return node; 
        }

        return balance(node);
    }

    void printNodeInfo(Node* node) {
        if (!node) return;

        printNodeInfo(node->left);
        std::cout << "Value: " << node->value
             << ", Height: " << node->height
             << ", Left: " << (node->left ? std::to_string(node->left->value) : "NULL")
             << ", Right: " << (node->right ? std::to_string(node->right->value) : "NULL")
             << std::endl;
        printNodeInfo(node->right);
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int value) {
        root = insertNode(root, value);
    }

    void printTreeInfo() {
        printNodeInfo(root);
    }
};

int main() {
    NAUP;
    
    AVLTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(60);
    tree.insert(10);
    tree.insert(40);
    tree.insert(0);
    tree.insert(45);
    tree.insert(43);

    std::cout << "AVL Tree Node Information:" << std::endl;
    tree.printTreeInfo();

    return 0;
}
