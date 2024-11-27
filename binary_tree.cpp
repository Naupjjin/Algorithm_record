#include <iostream>
#define NAUP std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)

struct Node {
    int data;           // Node value
    Node* left;         // left node
    Node* right;        // right node
    Node* parent;       // parent node

    // Node constructor
    Node(int data) 
        : data(data), left(nullptr), right(nullptr), parent(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    // inorder traversal
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }

    // function about search a node
    Node* search(Node* node, int value) {
        // root is null pointer or success to find node
        if (node == nullptr || node->data == value) return node;
        // find left or right node
        if (value < node->data) return search(node->left, value);
        return search(node->right, value);
    }

public:
    // Constructor
    BinaryTree(Node* root = nullptr) : root(root) {}

    // insert node
    void insert(int value) {
        Node* newNode = new Node(value);
        Node* current = root;
        Node* parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (value < current->data) {
                current = current->left;
            } 
            else {
                current = current->right;
            }
        }

        newNode->parent = parent;

        if (parent == nullptr) { // if root node is null pointer, insert node as root node
            root = newNode;
        } 
        else if (value < parent->data) { // if now value < Parent Node, insert it into Parent Node's left
            parent->left = newNode;
        } 
        else { // if now value > Parent Node, insert it into Parent Node's Right
            parent->right = newNode;
        }
    }

    void deleteNode(int value) {
        Node* want_del_node = search(root, value);
        // root is null pointer 
        if(want_del_node == nullptr) return;
        
        /*
        delete have three case:
        1. want_del_node is leaf Node(left child and Right child are nullptr)
        2. want_del_node is parent Node and one of left and Right have value
        3. want_del_node is parent Node and all child node have value
        */
        
    
      
    }

    // print inorder traversal result
    void printInOrder() {
        inorder(root);
    }
    
};

int main() {
    NAUP;

    BinaryTree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    tree.printInOrder(); // Output: 3 5 7 10 15

    return 0;
}
