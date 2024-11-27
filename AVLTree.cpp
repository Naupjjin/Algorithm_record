#include <iostream>
#define NAUP std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)

struct Node{
    int data; // data
    Node* left; // Leaf left or right pointer
    Node* right; 
    Node* parent; // parent pointer
    int height; // node height on AVL tree

    // constructor
    Node(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr), height(0) {}
};

class AVLtree{
private:
    

    // inorder traversal
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }
    
    // Preorder traversal
    void preorder(Node* node) {
        if (node == nullptr) return;
        std::cout << node->data << " "; 
        preorder(node->left);          // Traverse left subtree
        preorder(node->right);         // Traverse right subtree
    }
    
    void _updateNodeHeight(Node* node) {
        if (node->parent != nullptr){
            node->height = node->parent->height + 1;
        } 
        else return;
    }

    void _getRightRotation() {
        
    }

    void _getLeftRotation() {
        
    }
    
    void _getBalanceFactor() {
        
    }
    
    int check_node_status(Node* node){
        if(node -> left == nullptr && node -> right == nullptr) return 0;
        else if(node -> left == nullptr and node -> right != nullptr) return 1;
        else if(node -> left != nullptr and node -> right == nullptr) return 2;
        else return 3;
    }
    
    void transplant(Node* u, Node* v) {
        if (u->parent == nullptr) {
            root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        if (v != nullptr) {
            v->parent = u->parent;
        }
    }
    
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

public:

    Node* root;
    
    void InsertNode(int value){
        Node* w_insert_node = new Node(value);
        if(root == nullptr){
            root = w_insert_node;
            return;
        }
        else{
            
            Node* current = root;
            Node* parent = nullptr;
            
            // find want to Insert Node's parent
            while(current != nullptr){
                _updateNodeHeight(current);
                parent = current;
                if(value < parent->data){
                    current = current->left;
                }
                else{
                    current = current->right;
                }
            }
            
            // Insert Node
            if(value < parent->data){
                parent->left = w_insert_node;
                w_insert_node->parent = parent;
            } 
            else{
                parent->right = w_insert_node;
                w_insert_node->parent = parent;
            }
            
            Node* node = w_insert_node;
            
            // updateHeight(your insert node to root path)
            _updateNodeHeight(node);
            
        }
        
    }
    
    void DeleteNode(int value) {
        Node* want_del_node = SearchNode(root, value);
        // root is null pointer 
        if(want_del_node == nullptr) return;
        
        /*
        delete have three case:
        case 0 want_del_node is leaf Node(left child and Right child are nullptr)
        case 1 2 want_del_node is parent Node and one of left and Right have value
        case 3 want_del_node is parent Node and all child node have value
        */
        
        switch(check_node_status(want_del_node)){
            case 0:
                transplant(want_del_node, nullptr);
                break;
            case 1:
                transplant(want_del_node, want_del_node->right);
                break;
            case 2:
                transplant(want_del_node, want_del_node->left);
                break;
            case 3:
                Node* MinNode = findMin(want_del_node->right);
                
                if (MinNode->parent != want_del_node) {
                    transplant(MinNode, MinNode->right);
                    MinNode->right = want_del_node->right;
                    MinNode->right->parent = MinNode;
                }
                
                transplant(want_del_node, MinNode);
                
                MinNode->left = want_del_node->left;
                MinNode->left->parent = MinNode;
                
                break;
        }
        
        delete want_del_node;
    }
    
    // function about search a node
    Node* SearchNode(Node* node, int value) {
        // root is null pointer or success to find node
        if (node == nullptr || node->data == value) {
            return node;
        }
        _updateNodeHeight(node);
        // find left or right node
        if (value < node->data) {
            return SearchNode(node->left, value);
        }
        else {
            return SearchNode(node->right, value);
        }
            
    }
    
    void printInOrder() {
        inorder(root);
    }
    
    void printPreOrder() {
        preorder(root);
    }
    
    // Use Debug
    void printNodeHeights(Node* node) {
        if (node == nullptr) return;
        printNodeHeights(node->left);
        std::cout << "-----\nNode: " << node->data << ", Height: " << node->height << "\n";
        if (node->left !=nullptr){
            std::cout << "node left: " << node->left->data << "\n";
        }
        else {
            std::cout << "node left: null" << "\n";
        }
        
        if (node->right !=nullptr){
            std::cout << "node right: " << node->right->data << "\n";
        }
        else {
            std::cout << "node right: null" << "\n";
        }
        
        if(node->parent != nullptr) {
            std::cout << "parent: " << node->parent->data << "\n";
        }
        else{
            std::cout << "parent: null(root)\n";
        }
        printNodeHeights(node->right);
    }



};

int main() {
    NAUP;
    AVLtree tree;
    
    tree.InsertNode(15);
    tree.InsertNode(10);
    tree.InsertNode(14);
    tree.InsertNode(1);
    tree.InsertNode(8);
    
    tree.printInOrder();
    std::cout << std::endl;
    tree.printPreOrder();
    std::cout << std::endl;
    tree.printNodeHeights(tree.SearchNode(tree.root, 15));
    
    
    tree.DeleteNode(10);
    tree.InsertNode(7);
    tree.printInOrder();
    std::cout << std::endl;
    tree.printPreOrder();
    std::cout << std::endl;
    // tree.printNodeHeights(tree.SearchNode(tree.root, 8));
    tree.printNodeHeights(tree.SearchNode(tree.root, 15));
    return 0;
}
