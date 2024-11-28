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

    // if node is empty, return zero(null leaf). Else return its height
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
        // when you find you want to insert place, directly update your node height
        updateHeight(node);
        
        // get balanceFactor (this node)
        int balanceFactor = getBalanceFactor(node);

        // RR LL RL LR balance
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
        /* 
        if node is nullptr, present root node is empty, setting the first node as root.
        anthor case is find we want to insert node place(this node is enpty, so we insert node on this place)
        */
        if (!node) return new Node(value);

        
        if (value < node->value) { // if value < node's value, travel to left tree
            node->left = insertNode(node->left, value);
        } 
        else if (value > node->value) { // if value > node's value, travel to right tree
            node->right = insertNode(node->right, value);
        } 
        else {
            return node; // if equal , directly return itself
        }

        // AVL tree's insert balnace
        return balance(node);
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
    
    void Remove(int value) {
        root = deleteNode(root, value);
    }

    void printTreeInfo() {
        printNodeInfo(root);
    }
};

int main() {
    NAUP;
    
    AVLTree tree;
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(10);
    tree.insert(25);
    tree.insert(50);

    std::cout << "------------:" << std::endl;
    tree.printTreeInfo();

    std::cout << "\n----------------:" << std::endl;
    tree.Remove(20);
    tree.printTreeInfo();

    std::cout << "\n---------------:" << std::endl;
    tree.Remove(30);
    tree.printTreeInfo();

    return 0;
}
